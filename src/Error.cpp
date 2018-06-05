#include <iostream>
#include "Error.h"

const std::string parseErrors[] = {
	/* 0. */ "No errors, program is syntactically correct.",
	/* 1. */ "Use = instead of :=.",
	/* 2. */ "= must be followed by a number.",
	/* 3. */ "Identifier must be followed by =.",
	/* 4. */ "const, int, procedure must be followed by identifier.",
	/* 5. */ "Semicolon or comma missing.",

	/* XXX ??? */
	/* 6. */ "Incorrect symbol after procedure declaration.",
	/* 7. */ "Statement expected.",
	/* 8. */ "Incorrect symbol after statement part in block.",
	/* XXX ??? */

	/* 9. */ "Period expected.",
	/* 10. */ "Semicolon between statements missing.",
	/* 11. */ "Undeclared identifier.",
	/* 12. */ "Assignment to constant or procedure is not allowed.",
	/* 13. */ "Assignment operator expected.",
	/* 14. */ "call must be followed by an identifier.",
	/* 15. */ "Call of a constant or variable is meaningless.",
	/* 16. */ "then expected.",

	/* XXX ??? */
	/* 17. */ "Semicolon or end expected.",
	/* XXX ??? */

	/* 18. */ "do expected.",

	/* XXX ??? */
	/* 19. */ "Incorrect symbol following statement.",
	/* XXX ??? */

	/* 20. */ "Relational operator expected.",
	/* 21. */ "Expression must not contain a procedure identifier.",
	/* 22. */ "Right parenthesis missing.",
	/* 23. */ "The preceding factor cannot begin with this symbol.",

	/* XXX ??? */
	/* 24. */ "An expression cannot begin with this symbol.",
	/* XXX ??? */

	/* 25. */ "This number is too large.",

	/* extra errors! */
	/* 26. */ "out must be followed by an expression.",
	/* 27. */ "in must be followed by an identifier.",
	/* 28. */ "Cannot reuse this symbol here.",
	/* 29. */ "Cannot redefine an ident.",
	/* 30  */ "Unexperted Token in a declaration.",
	/* 31  */ "The symbol do not exist in pl0.",
	/* 32  */ "Unrecognized token.",
	/* 33  */ "Empty file.",
	/* 34  */ "Unacceptale token in front of a statement.",
	/* 35  */ "Read a procedure is meaningless."
};

void printError(int errorId, int line)
{
	std::cout << parseErrors[errorId] << "in line" << line << std::endl;
	system("pause");
	exit(0);
}
