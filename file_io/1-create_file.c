#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * create_file - Creates a file and writes text content to it.
 * @filename: A pointer to the name of the file to create.
 * @text_content: A pointer to a string to write to the file.
 *
 * Return: If the function fails or filename is NULL - -1.
 * Otherwise - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, len = 0;
	ssize_t n_written;

	if (filename == NULL)
		return (-1);

	/* Mətnin uzunluğunu tapırıq (əgər NULL deyilsə) */
	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	/* Faylı yaradırıq (O_CREAT), yazmaq üçün açırıq (O_WRONLY), 
	   əgər varsa içini silirik (O_TRUNC). İcazə: 0600 (rw-------) */
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	/* Əgər text_content NULL deyilsə, fayla yazırıq */
	if (text_content != NULL)
	{
		n_written = write(fd, text_content, len);
		if (n_written == -1)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
