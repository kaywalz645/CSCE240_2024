#!/usr/bin/env python3
"""
Module documentation goes here
"""


import argparse
import subprocess
import sys
from xml.etree import ElementTree


def parse_output(output, test):
    """Method documentation goes here.
    """
    error_msg = "ERROR: {} EXPECTED: {}, ACTUAL: {}\n"
    # try parsing output
    root = None
    try:
        root = ElementTree.fromstring(output)
    except ElementTree.ParseError as parse_error:
        return (error_msg.format("XML Parse Error", "Valid XML Tree", parse_error)
            + "\n\tAborting Test...")

    if not test:
        return ""

    return_msg = ""
    # check root / demographics
    if root.tag != "demographics":
        return_msg = error_msg.format("Demographics Tag", "demographics", root.tag)

    if root.attrib['id'] != test['demographics']:
        return_msg += error_msg.format("Demographics ID",
                                      test['demographics'],
                                      root.attrib['id'])

    # check number of first level nodes / patients
    if len(root) != len(test['patients']):
        return_msg += error_msg.format("Patient Count",
                                       len(root),
                                       len(test['patients']))
        return return_msg

    # check each first level node / patient
    patient_index = 0
    for patient in root:
        if patient.tag != "patient":
            return_msg += error_msg.format("Patient Tag",
                                           "patient",
                                           patient.tag)

        if patient.attrib['id'] != test['patients'][patient_index]['id']:
            return_msg += error_msg.format(
                "Patient ID",
                test['patients'][patient_index]['id'],
                patient.attrib['id']
            )

        is_smoker = False
        for demographic_unit in patient:
            if demographic_unit.tag == "smoker":
                is_smoker = True
                if not test['patients'][patient_index]['smoker']:
                    return_msg += error_msg.format(
                        f"Patient {patient.attrib['id']} Smokes",
                        False,
                        True)
                continue
            elif demographic_unit.tag == "weight":
                weight = test['patients'][patient_index]['weight']
                if weight != int(demographic_unit.text):
                    return_msg += error_msg.format(
                      f"Patient {patient.attrib['id']} Weight",
                      weight,
                      int(demographic_unit.text))
                continue

            elif demographic_unit.tag == "birthday":
                birth_dict = test['patients'][patient_index]['birthday']
                if len(demographic_unit) != len(birth_dict):
                    return_msg += error_msg.format(
                        f"Patient {patient.attrib['id']} Birthday fields",
                        len(birth_dict),
                        len(demographic_unit))
                    return_msg += '\n'
                    continue
                for field in demographic_unit:
                    # check birthday text
                    if field.tag not in birth_dict:
                        return_msg += error_msg.format(
                            f"Patient {patient.attrib['id']} Birthday {field.tag}",
                            [key for key in birth_dict.keys()],
                            field.tag)
                        continue

                    if field.text != birth_dict[field.tag]:
                        return_msg += error_msg.format(
                            f"Patient {patient.attrib['id']} Birthday {field.tag}",
                            birth_dict[field.tag],
                            field.text)

            elif demographic_unit.tag == "ethnicities":
                # alias to type less
                ethnic_dict = test['patients'][patient_index]['ethnicities']
                if len(demographic_unit) != len(ethnic_dict):
                    return_msg += error_msg.format(
                        f"Patient {patient.attrib['id']} Ethnicity Count",
                        len(ethnic_dict),
                        len(demographic_unit))
                    return_msg += '\n'
                    continue
                if len(demographic_unit) == 0:
                    continue

                for ethnicity in demographic_unit:
                    # find ethnicity by id
                    if ethnicity.attrib['id'] not in ethnic_dict:
                        return_msg += error_msg.format(
                            f"Patient {patient.attrib['id']} Missing Ethnicity",
                            f"{ethnicity.attrib['id']} in {list(ethnic_dict.keys())}",
                            "not found"
                        )
                        continue
                    # check ethnicity text
                    if ethnicity.text != ethnic_dict[ethnicity.attrib['id']]:
                        return_msg += error_msg.format(
                            f"Patient {patient.attrib['id']} Ethnicity {ethnicity.attrib['id']}",
                            ethnic_dict[ethnicity.attrib['id']],
                            ethnicity.text)
            else:
                return_msg += error_msg.format(
                    "Demographic Units",
                    f"{demographic_unit.tag} in [\"exams\", \"ethnicities\"]",
                    "not found"
                )

        # check for smoker (gross)
        if test['patients'][patient_index]['smoker'] and not is_smoker:
            return_msg += error_msg.format(
                f"Patient {test['patients'][patient_index]['id']} Smokes ",
                True,
                False)

        patient_index += 1

    return return_msg


TEST_1 = {
    "file" : "demos_1.txt",
    "demographics" : "24sp",
    "patients" : [{
        "id" : "FFFFF",
        "birthday" : {"month" : "3", "day" : "1", "year" : "2002"},
        "weight" : 144,
        "smoker" : False,
        "ethnicities" : { 'N' : "American or Alaskan Native" }
    }, {
        "id" : "FFFFE",
        "birthday" : {"month" : "10", "day" : "30", "year" : "1998"},
        "weight" : 125,
        "smoker" : True,
        "ethnicities" : { 'B' : "African American" }
    }]
}

TEST_2 = {
    "file" : "demos_2.txt",
    "demographics" : "23sp",
    "patients" : [{
        "id" : "FFFFD",
        "birthday" : {"month" : "3", "day" : "1", "year" : "2002"},
        "weight" : 138,
        "smoker" : False,
        "ethnicities" : { 'B': "African American", 'W' : "White" }
    }, {
        "id" : "FFFFC",
        "birthday" : {"month" : "10", "day" : "30", "year" : "1998"},
        "weight" : 121,
        "smoker" : True,
        "ethnicities" : { }
    }, {
        "id" : "FFFFB",
        "ethnicities" : { 'P' : "Native Islander",
                          'A' : "Asian",
                          'H' : "Hispanic" },
        "birthday" : {"month" : "4", "day" : "17", "year" : "2005"},
        "weight" : 117,
        "smoker" : False,
    }]
}


class QuickTest:
    """Class documentation goes here
    """
    def __init__(self, test):
        self._exe = ["./parse-demographics"]
        self._timeout = 5

        self._test = TEST_1 if test == 1 else TEST_2


    def test(self):
        """Method documentation goes here
        """
        file_text = ""
        with open(self._test['file'], 'r', encoding="utf-8") as file_in:
            file_text = file_in.read()

        returncode, stdout = self.run(file_text)

        if returncode != 0:
            print(
                f"ERROR: EXPECTED return 0, ACTUAL return {returncode}.",
                file=sys.stderr)

        if not stdout:
            print("ERROR: No output from patient app.", file=sys.stderr)
            sys.exit(1)

        print("BEGIN STUDENT OUTPUT")
        print("------------------------")
        print(stdout.strip())
        print("------------------------")
        print("END STUDENT OUTPUT")

        result = parse_output(stdout, self._test)
        if result:
            print(result)
            print("TEST FAILED")
            return False
        print("TEST PASSED")
        return True


    def run(self, text_in):
        """Method documentation goes here.
        """
        try:
            result = subprocess.run(args=self._exe,
                                    input=text_in,
                                    universal_newlines=True,  # open IO in text mode
                                    stdout=subprocess.PIPE,
                                    stderr=subprocess.PIPE,
                                    timeout=self._timeout,
                                    check=False)
            return result.returncode, result.stdout

        except subprocess.TimeoutExpired:
            print("Timeout expired")
            return 10, None, f"Execution timed out after {self._timeout}s\n"

        except subprocess.CalledProcessError as proc_err:
            print(proc_err)
            return 1, None, f"Exited with code {proc_err.returncode}\n"


if __name__ == "__main__":
    CL_PARSER = argparse.ArgumentParser(
        prog='test_parse_demographics.py',
        description="Executes one of two tests on executable parse-demographics")
    CL_PARSER.add_argument('test', metavar="TEST_NUMBER", type=int,
                           choices={1, 2},
                           help="Test number from {1, 2}")
    ARGS = CL_PARSER.parse_args()

    TEST = QuickTest(ARGS.test)
    if TEST.test():
        sys.exit(0)
    sys.exit(1)
