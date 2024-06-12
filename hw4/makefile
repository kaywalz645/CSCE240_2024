# use g++ compiler using C++ 17 standard
cc = g++ -std=c++17

# root for include directive and linter
root = ..

# compile with all warnings
flags = -Wall -pedantic
# compile with root on #include root
flags += -I $(root)
# compile with instrumentation for gdb
flags += -g

# compilation to intermediary .o files
compile = $(cc) $(flags) -c -o

# final linked build to binary executable
link = $(cc) -o


# compile YOUR code
# demographic
bin/demographic.o : src/demographic.cc inc/demographic.h inc/date.h
	$(compile) $@ $<

# date
bin/date.o : src/date.cc inc/date.h
	$(compile) $@ $<


# lint code
# demographic
demographic-style : src/demographic.cc inc/demographic.h
	cpplint --root=$(root) $^
# date
date-style : src/date.cc inc/date.h
	cpplint --root=$(root) $^

# build and run against tests
#
test-demographic : bin/test_demographic.o bin/demographic.o bin/date.o
	$(link) $@ $^

test-date : bin/test_date.o bin/date.o
	$(link) $@ $^

test-date-bonus : bin/test_date_bonus.o bin/date.o
	$(link) $@ $^

# compile your code against MY tests
#
bin/test_demographic.o : src/test_demographic.cc inc/test_demographic.h inc/demographic.h inc/date.h
	$(compile) $@ $<

bin/test_date.o : src/test_date.cc inc/test_date.h inc/date.h
	$(compile) $@ $<

bin/test_date_bonus.o : src/test_date_bonus.cc inc/date.h
	$(compile) $@ $<

# running the code 
#
run-testdate: test-date
	./test-date

run-testdemo: test-demographic
	./test-demographic

clean:
	rm -f bin/* test-*
