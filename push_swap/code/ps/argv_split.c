
#include "ps.h"

char	**argv_split(char **argv, int argc)
{
	char	**spl;

	spl = (char **)malloc((argc + 1) * sizeof(char *));
	if (!spl)
		return (NULL);
	spl[argc] = NULL;
  argc--;
	while (argc >= 0)
  {
    spl[argc] = argv[argc];
    argc--; 
  }
	return (spl);
}
