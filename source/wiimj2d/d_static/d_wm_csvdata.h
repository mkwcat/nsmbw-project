#pragma once

class dCsvData_c
{
    SIZE_ASSERT(0x16518);

public:
    // Instance Methods
    // ^^^^^^

    /* 0x800F57C0 */
    char* GetPointName(int) const;

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x0, 0x16518);
};