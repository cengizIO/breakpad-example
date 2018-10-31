all:
	$(CXX) -O0 \
		`pkg-config --cflags --libs breakpad` \
		main.cpp \
		-lbreakpad_client \
		-o breakpad_test

clean:
	rm -f breakpad_test
