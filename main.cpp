#include <stdio.h>
#include <string>
#include "client/linux/handler/exception_handler.h"

static bool dumpCallback(const google_breakpad::MinidumpDescriptor& dp,
			void* context, 
			bool succeeded) {
	printf("Dump path: %s\n", dp.path());
	return succeeded;
}

void crash() { 
	volatile int* a = (int*)(NULL); 
	*a = 1; 
}

int main(int argc, char* argv[]) {
	google_breakpad::MinidumpDescriptor descriptor("/tmp");
	google_breakpad::ExceptionHandler eh(descriptor, NULL, dumpCallback, NULL, true, -1);
	crash();
	return 0;
}
