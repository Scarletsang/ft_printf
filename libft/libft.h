/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:21:27 by htsang            #+#    #+#             */
/*   Updated: 2022/11/02 16:03:01 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

///////////////////////////
//// basic functions //////
///////////////////////////

int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
/*
** @brief Check if the character is between 32 and 126.
** Printable characters include the space (32).
*/
int		ft_isprint(int c);
int		ft_isalnum(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

///////////////////////////
//// string functions /////
///////////////////////////

/*
** @param str: a NULL-terminated string
** @return the length of the given string
*/
size_t	ft_strlen(const char *str);
/*
** @brief Compare the first different byte found between two strings.
** Comparision stops when a string terminated.
**
** @param s1: 1st string.
** @param s2: 2nd string.
** @param max_len: the maximum length of bytes to compare
** @return 0 if both strings are identical in value,
** negative numbers if m1 < m2, positive numbers if m1 > m2.
*/
int		ft_strncmp(const char *s1, const char *s2, size_t max_len);
/*
** @brief Safe copy of the source string to the destination 
** string. It only copies up to a maximum amount of char.
**
** @param dest: the destination memory address to copy to.
** @param src:  a NULL-terminated string to be copied from.
** @param max_len: the maximum length of char to be copied.
** @return the length of the destination string after copying.
*/
size_t	ft_strlcpy(char *dest, const char *src, size_t max_len);
/* 
** @brief Safe concatenate of the source string after the
** destination string. Length of the string after concatenation
** (including the NULL-terminator) must be specified to ensure
** safe concatenation. Concatenation WILL NOT happen if the
** destination memory address does not have enough space to store
** the entire string after concatenation.
**
** @param dest: a string to concatenated after.
** @param src:  a NULL-terminated string to be copied to dest.
** @param max_len: the maximum length of the destination string after
** concatenation (including the NULL-terminator).
** @return the length of the result array, the expected length of 
** the result array is returned if there is not enough space to
** concatenate.
*/
size_t	ft_strlcat(char *dest, const char *src, size_t max_len);
/*
** @brief Locate the first occurance of a string(needle) in
** a longer string(haystack).
**
** @param haystack: a NULL-terminated string to be searched in
** @param needle:   a NULL-terminated string to find in haystack
** @param max_len:  the maximum length to search in the haystack
** @return the pointer to the needle location
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
/*
** @brief Locate the first given char in a given string.
**
** @param str: a NULL-terminated string
** @param c:   the value to find in the string, it is interpreted
** as char during search.
** @return the memory address of the value in the string
*/
char	*ft_strchr(const char *str, int c);
/*
** @brief Locate the last given char in a given string.
**
** @param str: a NULL-terminated string
** @param c:   the value to find in the string, it is interpreted
** as char during search.
** @return the memory address of the value in the string
*/
char	*ft_strrchr(const char *str, int c);
/*
** @brief Iterate on a string, apply a function on every char of
** the string. The function can change the char in the string but
** won't produce a new string like strmapi.
** 
** @param str: a NULL-terminating string
** @param f(index,char):   the function to be applied on every char,
** it takes 2 arguments: the char and its index in the string.
*/
void	ft_striteri(char *str, void (*f)(unsigned int, char*));
/*
** @brief converts a string into an int.
**
** @details When the number overflow at the long long
** level, the number will became negative, it returns 
** 0 or -1 depending on the size. Overflow on the int
** level is handled by the casting at the end.
** 
** @param str: the string that represents a number,
** multiple spaces, follow by one '-' or '+', is allowed.
** @return the int after convertion
*/
int		ft_atoi(const char *str);

////////////////////////////////////////
//// string functions with malloc //////
////////////////////////////////////////

/* 
** @brief Duplicates a string to a new memory address.
**
** @param str: a NULL-terminated stirng
** @return the new string after duplication from the given string
*/
char	*ft_strdup(const char *str);
/*
** @brief Cut a substring out of a given string by its starting index
** and length. Th substring is stored in a new memory address. The
** original string is left untouched.
**
** @param str:     a NULL-terminated string to cut the string from.
** @paarm start:   the starting index to cut from the string
** @param max_len: the maximum length to cut from the string
** @return the newly created substring
*/
char	*ft_substr(char const *str, unsigned int start, size_t max_len);
/*
** @brief Join two strings into a new memory. The second string
** is concatenated after the first string. It is equivalence
** to the "concat" function in other programming languages.
**
** @param s1: the 1st NULL-terminated string
** @param s2: the 2nd NULL-terminated string
** @return a new memory address storing the string after
** concatenation of the 2 original strings. NULL is returned if
** malloc fails.
*/
char	*ft_strjoin(char const *s1, char const *s2);
/*
** @brief Trim the start and end of a string by removing chars that
** is in the given set. The trimmed string is stored in a new memory
** address. The original string is not touched at all.
**
** @param str: a NULL-terminated string to be trimmed.
** @param set: a char array represents a set of chars that needs
** to be trimmed.
** @return the new trimmed string
*/
char	*ft_strtrim(char const *str, char const *set);
/* 
** @brief Allocate memory for an array of string that are
** splitted from a string str by delimiter c.
** 
** @param str: the string to be splitted
** @param c: delimiter
** @return the splitted string in an array
*/
char	**ft_split(char const *str, char c);
/*
** @brief Map a function over a string, and creates a new string
** from it. The given string will not be changed at all.
**
** @param str: a NULL-terminated string to be mapped over
** @param f(index,char):   the function to be applied on every char,
** it takes 2 arguments: the char and its index in the string.
** @return the new string
*/
char	*ft_strmapi(char const *str, char (*f)(unsigned int, char));
/*
** @brief Convert an int to a string, memory is allocated to
** the string.
**
** @param n: the int to be converted
** @return a NULL-terminated string that represents the int,
** NULL pointer is returned if malloc fails.
*/
char	*ft_itoa(int n);

////////////////////////////
//// memory functions //////
////////////////////////////

/*
** @brief set a given amount of 0 to a memory address.
**
** @param mem:  the memory address
** @param size: the amount
*/
void	ft_bzero(void *mem, size_t size);
/*
** @brief Allocate memory for a given amount of byte
** with a certain size. The memory is initialized with
** all bytes filled with 0.
** 
** @details SIZE_MAX / size < count ensures multiplication
** won't cause overflow in the malloc. Size is also
** checked because it will cause the division to fail
** when size is 0.
**
** @param count: amount of memory chunk
** @param size:  size of the memory chunk
** @return the memory address with the corresponding size,
** null when malloc fails.
*/
void	*ft_calloc(size_t count, size_t size);
/*
** @brief Locate the first occurance of a value in a byte string.
**
** @param mem:  the memory address
** @param val:  the value to look for, it is interpreted as an
** unsigned char during comparasion.
** @param max_size: the maximum size of byte to look for the value.
*/
void	*ft_memchr(const void *mem, int val, size_t max_size);
/*
** @brief Set a given amount of the same value
** to the given memory address.
**
** @param mem:  the memory address
** @param val:  the int value
** @param size: the amount of byte to write
** @return the original memory address
*/
void	*ft_memset(void *mem, int val, size_t size);
/*
** @brief Compare the first different byte found between two byte strings.
** Both byte strings are assumed to have the size of the third argument.
**
** @param m1: 1st byte string, interpreted as unsigned char during comparison.
** @param m2: 2nd byte string, interpreted as unsigned char during comparison.
** @param size: the size of both byte string
** @return 0 if both byte strings are identical in value,
** otherwise return the difference of the different byte, m1 - m2.
*/
int		ft_memcmp(const void *m1, const void *m2, size_t size);
/*
** @brief Copy a given size of memory from one byte string to another,
** assuming that NO memory overlapping is possible.
**
** @param dest: destination memory address to be copied to
** @param src:  source memory address to be copied from
** @param size: size of bytes to copy
** @return the destination memory address
*/
void	*ft_memcpy(void *dest, const void *src, size_t size);
/*
** @brief Copy a given size of memory from one byte string to
** another, assuming that memory overlapping IS possible.
** 
** @details Comparing the dest and src pointer to determine
** whether to copy bytes from the beginning or the end.
**
** @param dest: destination memory address to be copied to
** @param src:  source memory address to be copied from
** @param size: size of bytes to copy
** @return the destination memory address
*/
void	*ft_memmove(void *dest, const void *src, size_t size);

///////////////////////////
////// IO functions ///////
///////////////////////////

/*
** @brief Write a byte to the given file descripter.
**
** @param c:  the byte
** @param fd: the file descripter
*/
void	ft_putchar_fd(char c, int fd);
/*
** @brief Write a string to the given file descripter.
**
** @param str:  a NULL-terminated string
** @param fd: the file descripter
*/
void	ft_putstr_fd(char *str, int fd);
/*
** @brief write a string and a new line character
** to the given file descripter.
**
** @param str:  a NULL-terminated string
** @param fd: the file descripter
*/
void	ft_putendl_fd(char *str, int fd);
/*
** @brief Write an int to the given file descripter.
**
** @param n:  the interger to be written to the file descripter
** @param fd: the file descripter
*/
void	ft_putnbr_fd(int n, int fd);

////////////////////////////////////
////// Linked list functions ///////
////////////////////////////////////

/*
** @brief Creates a new node with the given content.
**
** @param content: The pointer to be stored in the content
** of the newly created node.
** @return a new node/a size-1 linked list, where lst.next is
** pointing to NULL.
*/
t_list	*ft_lstnew(void *content);
/*
** @brief Add a node to the start of linked list.
** Equivalence to the 'cons' function in Lisp.
**
** @param lst:   the memory address of the pointer pointing
** to the start of linked list.
** @param front: the node to be added
*/
void	ft_lstadd_front(t_list **lst, t_list *front);
/*
** @param lst: the start of a linked list
** @return the size of the linked list
*/
int		ft_lstsize(t_list *lst);
/*
** @param lst: the start of a linked list
** @return the last node of the linked list
*/
t_list	*ft_lstlast(t_list *lst);
/*
** @brief append a node to a linked list.
**
** @param lst:  the memory address of the pointer pointing
** to the start of linked list.
** @param back: the node to be appended
*/
void	ft_lstadd_back(t_list **lst, t_list *back);
/*
** @brief Free the space of and clear the content of the given node.
**
** @param lst: the node
** @param del: the delete function that is used to clear the content.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void*));
/*
** @brief Clear all memory that is used by the given linked list.
** 
** @param lst: the memory address of the pointer pointing
** to the start of linked list.
** @param del: the delete function that is used to delete the content
** of each node of the linked list.
*/
void	ft_lstclear(t_list **lst, void (*del)(void*));
/*
** @brief Iterate on a linked list, apply a function to
** change the content of each node of the linked list. Since
** this function will not make a new linked list, the function
** can also be used to invoke side effects that depends purely
** on the content on each node.
**
** @param lst: the start of the linked list
** @param f:   the function to be applied during iteration
*/
void	ft_lstiter(t_list *lst, void (*f)(void *));
/*
** @brief Map the content of a linked list to the content
** of a new linked list. A new linked list is created based on
** applying a function to every element of the given linked list.
**
** @param lst: the start of a linked list.
** @param f:   the function to be applied on every iteration to create
** new node on the new linked list.
** @param del: the function to clear teh new linked list if any malloc
** fails during the construction of the new linked list.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif