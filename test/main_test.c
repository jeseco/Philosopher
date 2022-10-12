/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseco <jeseco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:56:27 by jeseco            #+#    #+#             */
/*   Updated: 2022/10/10 15:14:05 by jeseco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmocka.h>

static void null_test_success(void **state) {
    (void) state;
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(null_test_success),
    };

   return cmocka_run_group_tests(tests, NULL, NULL); 
}
