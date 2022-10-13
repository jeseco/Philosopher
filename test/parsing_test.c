/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeseco <jeseco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:56:27 by jeseco            #+#    #+#             */
/*   Updated: 2022/10/12 14:15:25 by jeseco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>
#include <stdbool.h>

/* A test case that does nothing and succeeds. */
static void parsing_test_success(void **state) {
    (void) state;
    assert_true(true);
    assert_true(false);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(parsing_test_success),
    };

   return cmocka_run_group_tests(tests, NULL, NULL);
}
