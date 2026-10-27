/*
 * 2038-linux-bug
 * Copyright (C) k!M/pizslacker 2014-2026
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main (void)
{
    char *pn = "Epochalypse bug (S2C/Y2K38)";
    char *pv = "1.0";
    printf("%s v%s\n", pn, pv);
    printf("======================================\n");
    time_t t;
    t = (time_t) (0);
    printf ("          %d, %s", (int) t, asctime (gmtime (&t)));
    t = (time_t) (100000000);
    printf ("  %d, %s", (int) t, asctime (gmtime (&t)));
    t = (time_t) (900000000);
    printf ("  %d, %s", (int) t, asctime (gmtime (&t)));
    t = time ( NULL );
    printf (" %d, %s", (int) t, asctime (gmtime (&t)));
    t = (time_t) (2147483647);
    printf (" %d, %s", (int) t, asctime (gmtime (&t)));
    t++;
    printf ("%d, %s", (int) t, asctime (gmtime (&t)));
    return 0;
}
