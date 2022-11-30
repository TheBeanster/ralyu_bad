#include <stdio.h>
#include <stdlib.h>
#include "ral_memory.h"
#include "ral_file.h"

#include "ral_cli.h"
#include "ral_sourceunit.h"
#include "ral_lexer.h"



int main(int argc, char** argv)
{
	printf(" --- Ralyu interpreter ---\n");

	RalCLI_ReadArgs(argc, argv);

	Ral_TextFile* sourcefile = Ral_LoadTextFile(argv[1]);
	if (!sourcefile)
	{
		// Couldn't load source file
		return 0;
	}

	Ral_SourceUnit* mainsource = Ral_CreateSourceUnit(sourcefile);
	if (!mainsource)
	{
		// Couldn't create sourceunit from file
		return 0;
	}

	Ral_TokenizeSourceUnit(mainsource);

	

	Ral_DestroyTextFile(mainsource->file);
	Ral_FREE(mainsource);

	return 0;
}
