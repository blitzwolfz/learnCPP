#include <cstdio>
#include <cstring>
#include <stdexcept>

struct SimpleString {
	SimpleString(size_t max_size): max_size{ max_size },
		length{} {
		if (max_size == 0) {
			throw std::runtime_error{ "Max size must be at least 1." };
		}
		buffer = new char[max_size];
		buffer[0] = 0;
	}

	void print(const char* tag) const {
		printf("%s: %s", tag, buffer);
	}

	bool append_line(const char* x) {
		const auto x_len = strlen(x);
		if (x_len + length + 2 > max_size) return false;
		
		#pragma warning(suppress : 4996)
		std::strncpy(buffer + length, x, max_size - length);
		length += x_len;
		buffer[length++] = '\n';
		buffer[length] = 0;
		return true;
	}

	~SimpleString() {
		delete[] buffer; {
		}
	}
	private:
		size_t max_size;
		char* buffer;
		size_t length;
};


int main() {
	SimpleString string{ 115 };

	string.append_line("Starbuck, whaddya hear?");
	string.append_line("Nothin' but the rain.");

	string.print("A: ");

	string.append_line("Grab your gun and bring the cat in.");
	string.append_line("Aye-aye sir, coming home.");

	string.print("B: ");

	if (!string.append_line("Galactica!")) {
		printf("String was not big enough to append another message.\n");
	}
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file