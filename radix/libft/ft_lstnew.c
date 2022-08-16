#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	ptr = (t_list *)malloc(sizeof(*ptr));
	if (!(ptr))
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}
