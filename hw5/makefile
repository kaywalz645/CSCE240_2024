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
# statistic 
bin/statistic.o: src/statistic.cc inc/statistic.h
	$(compile) $@ $<
# median 
bin/median.o: src/median.cc inc/median.h inc/statistic.h
	$(compile) $@ $<


# lint code
#
test-median-style : src/median.cc inc/median.h
	cpplint --root=$(root) $^
test-statistic-style : src/statistic.cc inc/statistic.h
	cpplint --root=$(root) $^


# Statistic TEST
#
test-statistic: bin/test_statistic.o bin/statistic_test.o  \
                bin/median.o bin/statistic.o
	$(link) $@ $^
test-statistic-memory: test-statistic
	valgrind -s --leak-check=full ./$<

# BUILD
bin/test_statistic.o: src/test_statistic.cc inc/test_data.h \
                      inc/median.h inc/statistic.h
	$(compile) $@ $<

bin/statistic_test.o: src/statistic_test.cc inc/statistic_test.h  \
                      inc/test_data.h  \
                      inc/median.h inc/statistic.h
	$(compile) $@ $<


# Median TEST
#
test-median: bin/test_median.o bin/statistic_test.o \
             bin/median.o bin/statistic.o
	$(link) $@ $^
# BUILD
bin/test_median.o: src/test_median.cc inc/test_data.h inc/statistic_test.h  \
                   inc/median.h inc/statistic.h
	$(compile) $@ $<


# Catch all rule
#
all: test-statistic test-median
	./test-statistic
	./test-median
	valgrind -s --leak-check=full ./$<

# Utilities
clean:
	$(RM) bin/* test-*
