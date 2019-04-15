/* This file is part of the Neper software package. */
/* Copyright (C) 2003-2019, Romain Quey. */
/* See the COPYING file in the top-level directory. */

#include "neut_povray_.h"

int
neut_povray_check (void)
{
  int status;
  char *tmp = ut_alloc_1d_char (1000);
  char *tmp2 = ut_alloc_1d_char (1000);

  sprintf (tmp, "tmp%d", getpid ());
  sprintf (tmp2, "which povray 2> /dev/null > %s", tmp);
  status = system (tmp2);

  remove (tmp);

  ut_free_1d_char (tmp);
  ut_free_1d_char (tmp2);

  return status;
}

int
neut_povray_check_error (void)
{
  if (neut_povray_check () != 0)
  {
    ut_print_messagewnc (2, 72,
			 "Povray not found! Make sure it is available at the command line then run Neper again.\n");
    abort ();
  }

  return 0;
}
