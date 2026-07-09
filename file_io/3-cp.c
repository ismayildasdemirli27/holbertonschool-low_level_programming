#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void check_error(int file_from, int file_to, char *argv[]);

/**
 * check_error - Faylların düzgün açılıb-açılmadığını yoxlayır.
 * @file_from: Oxunacaq faylın deskriptoru.
 * @file_to: Yazılacaq faylın deskriptoru.
 * @argv: Arqumentlər vektoru (xəta mesajı üçün).
 */
void check_error(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - Bir faylın məzmununu digərinə kopyalayır.
 * @argc: Arqumentlərin sayı.
 * @argv: Arqumentlər vektoru.
 *
 * Return: Uğurlu olduqda Həmişə 0 qaytarır.
 */
int main(int argc, char *argv[])
{
	int from, to, err_close;
	ssize_t nchars, nwr;
	char buf[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	from = open(argv[1], O_RDONLY);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	check_error(from, to, argv);

	while ((nchars = read(from, buf, 1024)) > 0)
	{
		nwr = write(to, buf, nchars);
		if (nwr == -1)
			check_error(0, -1, argv);
	}

	if (nchars == -1)
		check_error(-1, 0, argv);

	err_close = close(from);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", from);
		exit(100);
	}

	err_close = close(to);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", to);
		exit(100);
	}

	return (0);
}
