#include "ral_lexer.h"

#include "ral_memory.h"
#include "ral_sourceunit.h"



Ral_Statement* Ral_CreateStatement(
	const Ral_Token* const	begin,
	const Ral_Token* const	end,
	const Ral_StatementType type,
	const Ral_SourceUnit* const parentsource
)
{
	// Count the number of tokens in the statement
	int numtokens = 0;
	Ral_Token* iterator = begin;
	while (1)
	{
		numtokens++;
		if (iterator == end) break;
		iterator = iterator->next;
		if (!iterator)
			return NULL;
	}

	Ral_Statement* statement = Ral_ALLOC_TYPE(Ral_Statement);
	statement->numtokens = numtokens;
	statement->tokens = Ral_CALLOC(numtokens, sizeof(Ral_Token));
	iterator = begin;
	for (int i = 0; i < numtokens; i++)
	{
		statement->tokens[i] = *iterator;
		iterator = iterator->next;
	}

	statement->type = type;
	statement->parentsource = parentsource;

	return statement;
}

void Ral_DestroyStatement(Ral_Statement* const statement)
{
	for (int i = 0; i < statement->numtokens; i++)
	{
		Ral_DestroyToken(&statement->tokens[i]);
	}
	Ral_FREE(statement);
}
