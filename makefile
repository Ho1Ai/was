CC = gcc
SOURCE = src/main.c src/reader/reader.c src/reader/lines_counter.c src/initializer/initializer.c src/lex/lex.c src/parser/parser.c

FINAL = build/was

$(FINAL):$(SOURCE)
	$(CC) $(SOURCE) -o $(FINAL)
