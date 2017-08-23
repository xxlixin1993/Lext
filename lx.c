/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2017 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_lx.h"

/* If you declare any globals in php_lx.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(lx)
*/

/* True global resources - no need for thread safety here */
static int le_lx;

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("lx.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_lx_globals, lx_globals)
    STD_PHP_INI_ENTRY("lx.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_lx_globals, lx_globals)
PHP_INI_END()
*/
/* }}} */

/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_lx_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_lx_compiled)
{
	char *arg = NULL;
	size_t arg_len, len;
	zend_string *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &arg, &arg_len) == FAILURE) {
		return;
	}

	strg = strpprintf(0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "lx", arg);

	RETURN_STR(strg);
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and
   unfold functions in source code. See the corresponding marks just before
   function definition, where the functions purpose is also documented. Please
   follow this convention for the convenience of others editing your code.
*/


/* {{{ php_lx_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_lx_init_globals(zend_lx_globals *lx_globals)
{
	lx_globals->global_value = 0;
	lx_globals->global_string = NULL;
}
*/
/* }}} */


// 类
zend_class_entry *lx_ce;



/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(lx)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(lx)
{
#if defined(COMPILE_DL_LX) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(lx)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(lx)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "lx support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */


// construct method
ZEND_METHOD(Lx, __construct)
{
	php_printf("construct method\n");
}

// destruct method
ZEND_METHOD(Lx, __destruct)
{
	php_printf("destruct method\n");
}

// talk method
ZEND_METHOD(Lx, talk)
{
	php_printf("public method talk\n");
}
/* {{{ lx_functions[]
 *
 * Every user visible function must have an entry in lx_functions[].
 */
const zend_function_entry lx_functions[] = {
	PHP_FE(confirm_lx_compiled,	NULL)		/* For testing, remove later. */
	ZEND_ME(Lx, __construct, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
	ZEND_ME(Lx, __destruct, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_DTOR)
	ZEND_ME(Lx, talk, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	PHP_FE_END	/* Must be the last line in lx_functions[] */
};
/* {{{ PHP_MINIT_FUNCTION
 */

PHP_MINIT_FUNCTION(lx)
{
	zend_class_entry ce;
	INIT_CLASS_ENTRY(ce, "Lx\\Mian", lx_functions);
	lx_ce = zend_register_internal_class(&ce TSRMLS_CC);
	/* If you have INI entries, uncomment these lines
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ lx_module_entry
 */
zend_module_entry lx_module_entry = {
	STANDARD_MODULE_HEADER,
	"lx",
	lx_functions,
	PHP_MINIT(lx),
	PHP_MSHUTDOWN(lx),
	PHP_RINIT(lx),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(lx),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(lx),
	PHP_LX_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_LX
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(lx)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
