/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   stat.c                                                                   */
/*                                                                            */
/*   By: Thibault Cheneviere <thibault.cheneviere@telecomnancy.eu>            */
/*                                                                            */
/*   Created: 2022/11/09 08:28:12 by Thibault Cheneviere                      */
/*   Updated: 2022/11/09 08:35:16 by Thibault Cheneviere                      */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stat.h"

off_t get_file_size(const char *path) {
	struct stat st;

	if (!stat(path, &st))
		return st.st_size;

	return -1;
}

double get_seconds_from_last_modification(const char *file_path) {
    struct stat st;
    char *cp_path;

    cp_path = (char *)malloc(sizeof(char) * (strlen(file_path) + 1));
    strcpy(cp_path, file_path);

    if (stat(cp_path, &st) == 0)
    {
        time_t t = st.st_mtime;
        time_t now = time(NULL);

        // Free memory
        free(cp_path);

        return difftime(now, t);
    }

    // Free memory
    free(cp_path);

    return -1;
}
