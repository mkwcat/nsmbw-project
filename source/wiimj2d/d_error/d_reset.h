#pragma once

namespace dReset {

class Manage_c {
public:
    // Static Methods
    // ^^^^^^

    /* 0x80108020 */
    static Manage_c* GetInstance();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80108340 */
    void SetSoftResetFinish();
};

} // namespace dReset
