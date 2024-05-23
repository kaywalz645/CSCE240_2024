cc = g++ -std=c++17  # use g++ compiler with C++ 17 source code

root = ..  # define root of project/system as parent dir

flags = -Wall      # compile with all warnings
flags += -I $(root) # compile with root on include preproc path
flags += -g         # compile with GDB instrumentation

link = $(cc) $(flags) -o  # final linked build to binary executable

compile = $(cc) $(flags) -c -o  # compilation to intermediary .o files


bin/parse_demographics.o : src/parse_demographics.cc inc/parse_demographics.h
	$(compile) $@ $<


test-parse-demographics: bin/parse_demographics.o bin/test_parse_demographics.o
	$(link) $@ $^

bin/test_parse_demographics.o : src/test_parse_demographics.cc  \
                                inc/test_parse_demographics.h \
                                inc/parse_demographics.h
	$(compile) $@ $<


style-parse-demographics : src/parse_demographics.cc inc/parse_demographics.h
	cpplint --root=$(root) $^


test-1 : test-parse-demographics
	./test-parse-demographics 1

test-1-delete: test-parse-demographics
	./test-parse-demographics 1 delete

test-1-mem-leak : test-parse-demographics
	valgrind --leak-check=full ./test-parse-demographics 1 delete


test-2 : test-parse-demographics
	./test-parse-demographics 2

test-2-delete: test-parse-demographics
	./test-parse-demographics 2 delete

test-2-mem-leak : test-parse-demographics
	valgrind --leak-check=full ./test-parse-demographics 2 delete


test-all : test-parse-demographics
	./test-parse-demographics 1
	./test-parse-demographics 2

test-all-delete: test-parse-demographics
	./test-parse-demographics 1 delete
	./test-parse-demographics 2 delete

test-all-mem-leak : test-parse-demographics
	valgrind --leak-check=full ./test-parse-demographics 1 delete
	valgrind --leak-check=full ./test-parse-demographics 2 delete

clean:
	$(RM) bin/*.o test-parse-demographics
