#ifndef UVIEW_FITZ_FUNCTION_H
#define UVIEW_FITZ_FUNCTION_H

#include "uview/fitz/system.h"
#include "uview/fitz/context.h"
#include "uview/fitz/store.h"
#include "uview/fitz/colorspace.h"

/*
 * The generic function support.
 */

typedef struct fz_function_s fz_function;

void fz_eval_function(fz_context *ctx, fz_function *func, const float *in, int inlen, float *out, int outlen);
fz_function *fz_keep_function(fz_context *ctx, fz_function *func);
void fz_drop_function(fz_context *ctx, fz_function *func);
unsigned int fz_function_size(fz_context *ctx, fz_function *func);
void fz_print_function(fz_context *ctx, fz_output *out, fz_function *func);

enum
{
	FZ_FN_MAXN = FZ_MAX_COLORS,
	FZ_FN_MAXM = FZ_MAX_COLORS
};

struct fz_function_s
{
	fz_storable storable;
	unsigned int size;
	int m;					/* number of input values */
	int n;					/* number of output values */
	void (*evaluate)(fz_context *ctx, fz_function *func, const float *in, float *out);
	void (*print)(fz_context *ctx, fz_output *out, fz_function *func);
};

#endif
