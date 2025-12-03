/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:30:24 by sandrzej          #+#    #+#             */
/*   Updated: 2025/12/03 12:39:53 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include "printf/ft_printf.h"

typedef struct s_command
{
  char *command;
  char **params;
  char *path;
  char *name;
} t_command;

typedef struct s_data
{
char **argv_split;
char **paths;
char *infile;
char *incontent;  
char *outfile;
t_command *cmd;
int cmd_count;
} t_data;


// perror - prints a message to stderror
// void perror(const char *string);

char	**argv_split(char **argv, int argc);
void	f_sp(char **sp);
void initalize(t_data *data, int argc, char **argv, char **envp);
void end(t_data *data, char *str);
void validate_data(t_data *data);

// strerror - returns a string describing the error message
// char *strerror(int errnum);

// dup dup2 - already open file description duplication
// int dup(int oldfd);
// int dup2(int oldfd, int newfd); - specific number

// fork - creates a new process by duplicating the calling process.
/* •  The child inherits copies of the parent's set of open file
descriptors.  Each file descriptor in the child refers to the
same open file description (see open(2)) as the corresponding
file descriptor in the parent.  This means that the two file
descriptors share open file status flags, file offset, and
signal-driven I/O attributes (see the description of F_SETOWN
and F_SETSIG in fcntl(2)). */
//  pid_t fork(void);

// pipe - a unidirectional data channel that can be
//  used for interprocess communication. 
// int pipe(int pipefd[2]);
// struct fd_pair {
//  long fd[2];
//  };

// unlink - delete a filename
// int unlink(const char *path);

// wait
// waitpid
// pid_t wait(int *_Nullable wstatus);
//pid_t waitpid(pid_t pid, int *_Nullable wstatus, int options);
// All of these system calls are used to wait for state changes in a
//  child of the calling process, and obtain information about the
//  child whose state has changed

#endif
