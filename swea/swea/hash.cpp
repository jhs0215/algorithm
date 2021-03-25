#include <stdio.h>

#define MAX_LENGTH 11
#define MAX_HASH 1000

struct tagHash
{
	char key[MAX_LENGTH] = {0};
	char value[MAX_LENGTH] = {0};
};

tagHash hashmap[MAX_HASH];

int getHash(const char* str)
{
	int hashId = 5381;

	int ch;
	while (ch = *str++)
	{
		hashId = (((hashId << 5) + hashId) + ch) % MAX_HASH;
	}

	return hashId % MAX_HASH;
}

int is_same(const char* src, const char* dest)
{
	while (src[0] != 0 && dest[0] != 0)
	{
		if (src[0] != dest[0])
			return 0;

		src++;
		dest++;
	}

	return (src[0] == 0 && dest[0] == 0);
}

void copy(const char* src, char* dest)
{
	while (src[0] != 0)
	{
		dest[0] = src[0];

		src++;
		dest++;
	}

	dest[0] = 0;
}

int insert(char* key, char* value)
{
	int h = getHash(key);	
	for (int i = 0; i < MAX_HASH; ++i)
	{
		if (hashmap[h].key != 0)
		{
			if (is_same(hashmap[h].key, key))
				return 0;
		}
		else
		{
			break;
		}

		h = (h + 1) % MAX_HASH;
	}

	copy(key, hashmap[h].key);
	copy(value, hashmap[h].value);

	return 1;
}

int find(const char* key, char* value)
{
	int h = getHash(key);

	for (int i = 0; i < MAX_HASH; ++i)
	{
		if (hashmap[h].key == 0)
		{
			return 0;
		}
		else if (is_same(hashmap[h].key, key))
		{
			copy(hashmap[h].value, value);
			return 1;
		}

		h = (h + 1) % MAX_HASH;
	}

	return 0;
}

int main()
{
	return 0;
}