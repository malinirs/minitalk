#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h> /** for SIGUSR1 and SIGUSR2 */
# include <unistd.h> /** for get pid */
# include <stdlib.h>

size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);

#endif