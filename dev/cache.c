
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/require.h"
#include "kernel/object.h"
#include "kernel/debug.h"
#include "kernel/assert.h"
#include "kernel/array.h"

#include "zend_operators.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"

/**
 * Phalcon_Cache
 *
 * Phalcon_Cache could be use to caches output fragments for improve perfomace
 */

/**
 * Factories diferent caches backends from its adapters
 *
 * @paramstring $adapter
 * @paramarray $frontendOptions
 * @paramarray $backendOptions
 * @static
 */
PHP_METHOD(Phalcon_Cache, factory){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p2[] = { NULL, NULL };
	zend_class_entry *ce0;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|zz", &v0, &v1, &v2) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CONCAT_LEFT(r0, "Phalcon_Cache_Adapter_", v0);
	PHALCON_CPY_WRT(v3, r0);
	PHALCON_ALLOC_ZVAL(r1);
	Z_ADDREF_P(v3);
	p0[0] = v3;
	PHALCON_CALL_FUNC_PARAMS(r1, "class_exists", 1, p0);
	if (!zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_cache_exception_class_entry);
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_concat_both(r2,  "Adapter \"", v0, "' doesn't exist" TSRMLS_CC);
		Z_ADDREF_P(r2);
		p1[0] = r2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	ce0 = zend_fetch_class(Z_STRVAL_P(v3), Z_STRLEN_P(v3), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(i1);
	object_init_ex(i1, ce0);
	Z_ADDREF_P(v1);
	p2[0] = v1;
	Z_ADDREF_P(v2);
	p2[1] = v2;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 2, p2, PHALCON_CALL_CHECK);
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(i1);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
}
