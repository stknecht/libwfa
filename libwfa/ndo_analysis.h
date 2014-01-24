#ifndef LIBWFA_NDO_ANALYSIS_H
#define LIBWFA_NDO_ANALYSIS_H

#include <utility>
#include "ev_data_i.h"
#include "export_densities_i.h"
#include "export_orbitals_i.h"

namespace libwfa {


/** \brief Perform complete NDO analysis of a transition density matrix

     \ingroup libwfa
 **/
class ndo_analysis {
public:
    typedef std::pair<ab_matrix, ab_matrix> ab_matrix_pair;

private:
    const arma::Mat<double> &m_s; //!< Overlap matrix
    const ab_matrix &m_c; //!< MO coefficients

public:
    /** \brief Constructor
        \param s Overlap matrix
        \param c Orbital coefficient matrix for transform in orthogonal basis
     **/
    ndo_analysis(const arma::Mat<double> &s, const ab_matrix &c) :
        m_s(s), m_c(c) { }

    /** \brief Perform NDO analysis
        \param[in] ddm Difference density matrix
        \param[out] ad Attachment / detachment densities (first attach)
        \param[out] ndo_print Printer of NTOs
        \param[out] pr Printer of NTO data
     **/
    void perform(const ab_matrix &ddm, ab_matrix_pair &ad,
        export_orbitals_i &ndo_print, ev_data_i &pr) const;

    /** \brief Perform NDO analysis
        \param[in] ddm Difference density matrix
        \param[out] dm_print Printer of density matrices
        \param[out] ndo_print Printer of NTOs
        \param[out] pr Printer of NTO data
     **/
    void perform(const ab_matrix &ddm, export_densities_i &dm_print,
        export_orbitals_i &ndo_print, ev_data_i &pr) const;
};

} // namespace adcman

#endif
