CC = gcc 
C_LIBS = -lm
TEST_LIBS = -lcheck -lpthread -lm
CFLAGS = -std=c11 
SOURCES = $(wildcard s21_*.c)
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))

all: build

build: test

test: s21_matrix.a
	$(CC) $(CFLAGS) tests/test_matrix.c s21_matrix.a $(TEST_LIBS) -o test
	./test
	rm -rf *.o

s21_matrix.a: $(OBJECTS)
	ar rcs s21_matrix.a $(OBJECTS)
	ranlib s21_matrix.a

gcov_flag:
	$(eval CFLAGS += --coverage)

debug_flag:
	$(eval CFLAGS += -g)

gcov_report: clean gcov_flag test
	mkdir -p gcov
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory gcov
	open gcov/index.html
	rm -rf *.gcno *.gcda *.gcov

rebuild: clean all

style:
	clang-format -style=Google -i *.c *.h
	clang-format -style=Google -n *.c *.h

clean:
	rm -rf *.a *.o tests/*.o test *.a *.gcno *.gcda *.gcov *.info
