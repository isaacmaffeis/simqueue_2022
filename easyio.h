/*----------------------------------------------------------------------*/
/*                                                                      */
/*                               easyio.h                               */
/*                                                                      */
/*      This module contains the header for the functions exported by   */
/*			the easyio C++ package				*/
/*                                                                      */
/*----------------------------------------------------------------------*/

#ifndef _EASYIOPLUS_H
#define _EASYIOPLUS_H

#define EASYIO_MAX_INT_LEN 		9   /* max integer = (10E10 - 1) */
#define EASYIO_MAX_FLOAT_LEN 		15
#define EASYIO_MAX_STR_LEN 		80
#define EASYIO_MAX_BUF_LEN 		80

#define	EIO_MIN_INT 			-1000000000
#define	EIO_MAX_INT  			1000000000
#define EASYIO_OKAY 			0
#define EASYIO_ERROR 			1
#define EASYIO_DEFAULT 			2

#define true 				1
#define false 				0

extern		int	scandigit (int *);
extern		int	scanint (int *);
extern		int	scanlong (long *);
extern		int	scandouble (double *);
extern		int	scanstring (char *);

extern		void 	clear_screen();
extern		void 	beep();
extern		void 	pausa();
extern		char	readln ();

extern	 	short 	read_bool(const char *, short);
extern		short 	read_bool(const char *);

extern	 	int 	read_digit(const char *, int, int, int);
extern		int 	read_digit(const char *, int);
extern		int 	read_digit(const char *);

extern		int 	read_int(const char *, const char *, int, int, int);
extern		int 	read_int(const char *, int, int, int);
extern		int 	read_int(const char *, const char *, int);
extern		int 	read_int(const char *, int);
extern		int 	read_int(const char *);

extern		long 	read_long(const char *, const char *, long, long, long);
extern		long 	read_long(const char *, long, long, long);
extern		long 	read_long(const char *, const char *, long);
extern		long 	read_long(const char *, long);
extern		long 	read_long(const char *);

extern		double 	read_double(const char *, const char *, double, double, double);
extern		double 	read_double(const char *, double, double, double);
extern		double 	read_double(const char *, const char *, double);
extern		double 	read_double(const char *, double);
extern		double 	read_double(const char *);

extern		const char * 	read_string(const char *, const char *);
extern		const char * 	read_string(const char *);

extern		bool 	read_bool(const char*, int, int, int);
extern		bool	read_bool(const char*, int);


#endif    // _EASYIOPLUS_H
