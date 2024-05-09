cc = g++  # use g++ compiler
path = ..
standard = c++17

flags = -std=$(standard)  # compile with standard
flags += -Wall  # compile with all warnings
flags += -pedantic  # even more warnings
flags += -g  # add GDB debugging instrumentation
flags += -I $(path)  # add parent to preprocessor include path

link = $(cc) $(flags) -o  # final linked build to binary executable

compile = $(cc) $(flags) -c -o  # compilation to intermediary .o files


test-1 : parse-demographics
	python3 test_parse_demographics.py 1

test-2 : parse-demographics
	python3 test_parse_demographics.py 2

parse-demographics : parse_demographics.o
	$(link) $@ $<

parse_demographics.o : parse_demographics.cc
	$(compile) $@ $<

clean:
	$(RM) parse-demographics parse_demographics.o
