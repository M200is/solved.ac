#include <stdio.h>
#include <string.h>

int main()
{
  char input[65], rot[64], result[64], result2[65];
  int i, j, k;
  
  puts("Input: ");
  scanf("%s", input);
  
  if (strlen(input) == 64)
  {
    // Step 1: XOR with 3
    for (k = 0; k <= 64; ++k)
      result2[k] = result[k] ^ 3;
    
    // Step 2: Reconstruct rot array
    for (j = 1; j <= 62; ++j)
      rot[63 - j] = result2[j];
    rot[0] = 64;
    
    
    // Step 4: Reconstruct input string
    for (i = 0; i <= 63; ++i)
    {
      input[i] = (rot[i] - 13) & 0x7F;
    }
    
    // Output the result
    printf("%s", input);
  }
  else
  {
    puts("Invalid input.");
  }

  return 0;
}
