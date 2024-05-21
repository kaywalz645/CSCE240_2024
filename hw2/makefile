cc = g++ -std=c++17  # use g++ compiler with C++ 17 source code

root = ..  # define root of project/system as parent dir

flags = -Wall      # compile with all warnings
flags += -I $(root) # compile with root on include preproc path
flags += -g         # compile with GDB instrumentation

link = $(cc) $(flags) -o  # final linked build to binary executable

compile = $(cc) $(flags) -c -o  # compilation to intermediary .o files


bin/parse_demographics.o : src/parse_demographics.cc inc/parse_demographics.h
	$(compile) $@ $<

parse-demographics-style : src/parse_demographics.cc inc/parse_demographics.h
	cpplint --root=$(root) $^


test-all : test-parse-num-patients test-parse-num-ethnicities  \
           test-parse-ethnicity-values
	./test-parse-num-patients
	./test-parse-num-ethnicities
	./test-parse-ethnicity-values


test-parse-num-patients : bin/test_parse_num_patients.o bin/parse_demographics.o
	$(link) $@ $^
bin/test_parse_num_patients.o : src/test_parse_num_patients.cc  \
                                inc/parse_demographics.h
	$(compile) $@ $<


test-parse-num-ethnicities : bin/test_parse_num_ethnicities.o  \
                             bin/parse_demographics.o
	$(link) $@ $^
bin/test_parse_num_ethnicities.o : src/test_parse_num_ethnicities.cc  \
                                   inc/parse_demographics.h
	$(compile) $@ $<


test-parse-ethnicity-values : bin/test_parse_ethnicity_values.o  \
                              bin/parse_demographics.o
	$(link) $@ $^
bin/test_parse_ethnicity_values.o : src/test_parse_ethnicity_values.cc  \
                                    inc/parse_demographics.h
	$(compile) $@ $<


clean:
	$(RM) bin/*.o test-*
