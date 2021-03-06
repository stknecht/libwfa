#ifndef LIBWFA_POP_ANALYSIS_DM_TEST_H
#define LIBWFA_POP_ANALYSIS_DM_TEST_H

#include "test_base.h"

namespace libwfa {


/** \brief Tests the libwfa::pop_analysis_dm class

    \ingroup libwfa_tests
 **/
class pop_analysis_dm_test : public test_base {
public:
    virtual void perform() throw(libtest::test_exception);

private:
    template<typename TestData>
    void test_1() throw(libtest::test_exception);
};


} // namespace libwfa

#endif // LIBWFA_POP_ANALYSIS_DM_TEST_H
