#include <stdio.h>
#include <stdint.h>

void print_binary(uint32_t value)
{
	for (int i = 31; i >= 0; i--)
	{
		printf("%d", (value >> i) & 1);
	}
	printf("\n");
}

uint32_t replace_field(uint32_t reg, uint32_t val, uint8_t pos, uint8_t len) {
   
    return val << len;
}

int main() {
    uint32_t reg, val;
    uint8_t pos, len;
    scanf("%u %u %hhu %hhu", &reg, &val, &pos, &len);
    print_binary(replace_field(reg, val, pos, len));
    return 0;
}