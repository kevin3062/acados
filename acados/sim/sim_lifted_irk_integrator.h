/*
 *    This file is part of acados.
 *
 *    acados is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Lesser General Public
 *    License as published by the Free Software Foundation; either
 *    version 3 of the License, or (at your option) any later version.
 *
 *    acados is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with acados; if not, write to the Free Software Foundation,
 *    Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef ACADOS_SIM_SIM_LIFTED_IRK_INTEGRATOR_H_
#define ACADOS_SIM_SIM_LIFTED_IRK_INTEGRATOR_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "acados/utils/types.h"
#include "acados/sim/sim_rk_common.h"
#include "acados/sim/sim_collocation.h"

#define TRIPLE_LOOP 1
#define CODE_GENERATION 0

typedef struct sim_lifted_irk_workspace_ {
    real_t *rhs_in;
    real_t *jac_tmp;
    real_t **VDE_tmp;
    real_t *out_tmp;
    int_t *ipiv;

    real_t *sys_mat;
    real_t *sys_sol;
    real_t *sys_sol_trans;

    real_t *trans;
    struct d_strmat *str_mat;
    struct d_strmat *str_sol;

    real_t *out_adj_tmp;
} sim_lifted_irk_workspace;

typedef struct sim_lifted_irk_memory_ {
    real_t *K_traj;
    real_t *DK_traj;
    real_t *mu_traj;

    real_t **sys_mat2;
    real_t **sys_sol2;
    struct d_strmat **str_mat2;
    struct d_strmat **str_sol2;
    int_t **ipiv2;
    real_t *adj_traj;

    real_t **jac_traj;

    real_t *x;
    real_t *u;
    int_t nswaps;
} sim_lifted_irk_memory;


void sim_lifted_irk(const sim_in *in, sim_out *out,
        void *mem, void *work);

void sim_lifted_irk_create_workspace(const sim_in *in,
        sim_lifted_irk_workspace *work);

void sim_lifted_irk_create_memory(const sim_in *in,
        sim_lifted_irk_memory *mem);

void sim_irk_create_opts(int_t num_stages, const char* name, sim_RK_opts *opts);

void sim_irk_create_Newton_scheme(int_t num_stages, const char* name,
        sim_RK_opts *opts, enum Newton_type_collocation type);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif  // ACADOS_SIM_SIM_LIFTED_IRK_INTEGRATOR_H_
