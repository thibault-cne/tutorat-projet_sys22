/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   dirent.c                                                                 */
/*                                                                            */
/*   By: Thibault Cheneviere <thibault.cheneviere@telecomnancy.eu>            */
/*                                                                            */
/*   Created: 2022/11/09 08:12:49 by Thibault Cheneviere                      */
/*   Updated: 2022/11/21 14:07:56 by Thibault Cheneviere                      */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dirent.h"

void ft_fetch_path(const char *path) {
	DIR *dir;
	struct dirent *entry;

	if (!(dir = opendir(path)))
		return;
	
	while((entry = readdir(dir)) != NULL) {
		char *new_path;
		char *mime;

		if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, ".."))
			continue;

		new_path = (char *)malloc(sizeof(char) * (strlen(entry->d_name) + strlen(path) + 2));
		snprintf(new_path, strlen(entry->d_name) + strlen(path) + 2, "%s/%s", path, entry->d_name);

		mime = get_mime_type(entry->d_name);

		printf("%s %d %s %f\n", new_path, (int)get_file_size(new_path), mime, get_seconds_from_last_modification(new_path));

		free(mime);

		if (entry->d_type == DT_DIR)
			ft_fetch_path(new_path);

		free(new_path);
	}

	closedir(dir);
}
