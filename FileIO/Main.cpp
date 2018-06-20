#include <conio.h>
#include <fstream>

//_getch, _putch, _kbhit

namespace fio {
	bool isAlphaNumeric( char c ) {
		if ( c >= 48 && c <= 57 ) {
			return true;
		}

		if ( c >= 65 && c <= 122 ) {
			return true;
		}

		return false;
	}

	void print( const char* s ) {
		for ( ; *s != 0; s++ ) {
			_putch( *s );
		}
	}

	void read( char* buf, int maxSize ) {
		const char* const pEnd = buf + maxSize;
		char c = 0;

		while ( c != 13 && (buf < pEnd) ) {
			c = _getch();
			if ( isAlphaNumeric(c) ) {
				_putch( c );
				*buf = c;
				buf++;
			}
		}

		*buf = 0;
	}

	void readw( char* buf, int maxSize ) {
		const char* const pEnd = buf + maxSize;
		char c = 0;

		while ( c != 13 && (buf < pEnd+1) ) {
			c = _getch();
			if ( isAlphaNumeric(c)) {
				_putch( c );
				*buf = c;
				buf++;
			}
		}
		
		while(buf < pEnd ) {
			*buf = ' ';
			buf++;
		}

		buf--;

		*buf = 0;
	}

	int str2int( const char* s ) {
		const char* p = s;
		for ( ; *p >= '0' && *p <= '9'; p++ ) {}
		p--;

		int val = 0;
		int place = 1;

		for ( ; p >= s; p-- ) {
			val += (*p - '0') * place;
			place *= 10;
		}

		return val;
	}

	void strrev( char* pl ) {
		char* pr = pl;
		for ( ; *pr != 0; pr++ ) {}
		pr--;

		for ( ; pl < pr; pl++, pr-- ) {
			const char temp = *pl;
			*pl = *pr;
			*pr = temp;
		}
	}

	void int2str( int val, char* buf, const int size ) {
		char* const pStart = buf;
		char* const pEnd = buf + size;
		for ( ; val > 0 && (buf + 1 < pEnd); val /= 10, buf++ ) {
			*buf = '0' + val % 10;
		}
		*buf = 0;
		strrev( pStart );
	}

	int getLength( char* str ) {
		int len = 0;
		char* pl = str;
		while ( *pl != 0 ) {
			len++;
			pl++;
		}

		return len;
	}
}

char showMenu() {
	fio::print( "(l)oad (s)ave (a)dd (q)uit or (p)rint?\n" );
	char c = 0;
	while ( c == 0 ) {
		c = _getch();
		if ( c != 0 ) {
			return c;
		}
	}
}

struct nvPair {
	char name[10];
	char value[5];
};

void addNVPair( nvPair pairs[], const int nameLength, const int valueLength, const int nvIndex ) {
	fio::print( "Enter name: " );
	fio::readw( pairs[nvIndex].name, nameLength );
	fio::print( "\n" );
	fio::print( "Enter value: " );
	fio::read( pairs[nvIndex].value, valueLength );
	fio::print( "\n" );
}

void printChart( nvPair pairs[], const int nameLength, const int valueLength, int nvIndex ) {
	fio::print( "	Beautiful Chart Bitches!\n" );
	fio::print( "	------------------------\n\n" );

	for ( int j = 0; j < nvIndex; j++ ) {
		fio::print( pairs[j].name );
		fio::print( "|" );
		const int count = fio::str2int( pairs[j].value );

		for ( int i = 0; i < count; i++ ) {
			fio::print( "=" );
		}
		fio::print( "\n" );
	}
}



int main() {
	nvPair pairs[100];
	int nvIndex = 0;

	while ( 1 ) {
		switch ( showMenu() ) {
		case 'l':
			break;
		case 's':
			break;
		case 'a':
			addNVPair( pairs, 10, 5, nvIndex );
			nvIndex++;
			break;
		case 'q':
			return 0;
			break;
		case 'p':
			printChart( pairs, 10, 5, nvIndex );
			break;
		}
	}

	return 0;
}