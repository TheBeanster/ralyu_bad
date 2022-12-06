#pragma once

#include "ralu_stdinclude.h"
#include "ralu_list.h"

#include "ral_lexer.h"
#include "ral_object.h"
#include "ral_execute.h"



typedef struct Ral_FunctionParameter
{
	Ral_LISTLINKS(Ral_FunctionParameter);

	char* name;
	Ral_Type* type;
} Ral_FunctionParameter;

typedef Ral_Object (*(*Ral_ExternFunctionPtr)(Ral_List* parameters));

typedef struct Ral_Function
{
	Ral_LISTLINKS(Ral_Function);

	Ral_Statement* declaration; // Pointer to the statement declaring the function
	Ral_ExternFunctionPtr extern_function;

	Ral_List parameters; // List of Ral_FunctionParamater
} Ral_Function;



Ral_Object* Ral_CallFunction(
	Ral_State* const state,
	const Ral_Function* const function,
	const Ral_List* const parameters
);
