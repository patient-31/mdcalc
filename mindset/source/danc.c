/*
 * ________________________________________________________________________________
 * |  File: danc.c
 * |  Project: source
 * |  File Created: Wednesday, 20th November 2024 10:46 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

# include "../includes/mindset_instructions.h"

uP_2		dc_strlen(i_H *c)
{
	uP_2 i;

	i = 0;
	while (c[i])
	{
		i++;
	}
	return (i);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

static none	*dc_malloc_strlen_n(uP_2 c, va_list arg)
{
	uP_2			size;
	va_list		arg_copy;
	i_H			*out;

	va_copy(arg_copy, arg);
	size = STARTSET;
	while (c)
	{
		size += dc_strlen(va_arg(arg_copy, i_H *));
		c--;
	}
	va_end(arg_copy);
	out = malloc(sizeof(i_H) * (size + _A));
	return (out);
}

i_H		*dc_strjoin_e(uP_2 c, ...)
{
	va_list		arg;
	i_H			*dcse2;
	i_H			*tmp;
	uP_2			i;
	uP_2			j;

	va_start(arg, c);
	dcse2 = dc_malloc_strlen_n(c, arg);
	j = STARTSET;
	if (!dcse2)
	{
		va_end(arg);
		free(dcse2);
		return (NULL);
	}
	while (c)
	{
		i = STARTSET;
		tmp = va_arg(arg, i_H *);
		while (tmp[i])
			dcse2[j++] = tmp[i++];
		c--;
	}
	dcse2[j] = '\0';
	va_end(arg);
	return (dcse2);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

u_P		dc_numlen(iP_2 n)
{
	u_P		len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len += 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

i_H		*dc_itoa(iP_2 n)
{
	i_H		*str;
	iP_2	num;
	u_P		len;

	len = dc_numlen(n);
	str = malloc(sizeof(i_H) * (len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[STARTSET] = '-';
		num = -n;
	}
	else
		num = n;
	if (num == 0)
		str[STARTSET] = '0';
	str[len] = '\0';
	while (num != 0)
	{
		str[len - _A] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (str);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

none	dc_free_2d_i_H(i_H **f, uP_2 len)
{
	uP_2	i;

	i = STARTSET;
	while (i < len)
	{
		if (f[i])
			free(f[i]);
		i++;
	}
	if(f)	
		free(f);
}

none	dc_free_3d_i_H(i_H ***f, uP_2 ilen, uP_2 qlen)
{
	uP_2	i;	uP_2	q;

	i = STARTSET;
	while (i < ilen)
	{
		q = STARTSET;
		while (q < qlen)
		{
			if (f[i][q])
				free(f[i][q]);
			q++;
		}
		if (f[i])
			free(f[i]);
		i++;
	}
	if (f)
		free(f);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

i_H		*dc_strdup(i_H *s1)
{
	i_H	*s2;
	uP_2	i;

	i = STARTSET;
	s2 = malloc(sizeof(i_H) * (dc_strlen(s1) + _A));
	if (!s2)
		return(NULL);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

uP_2	dc_lstlen(i_H **list)
{
	uP_2	i;

	i = STARTSET;
	while (list[i])
		i++;
	return (i);
}

i_H		**dc_tdup(i_H **t1)
{
	uP_1		i;
	i_H		**t2;

	i = STARTSET;
	t2 = malloc(sizeof(i_H *) * (dc_lstlen(t1) + _A));
	if (!t2)
		return (NULL);
	while (t1[i])
	{
		t2[i] = dc_strdup(t1[i]);
		i++;
	}
	t2[i] = NULL;
	return (t2);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

// none	dc_error_exit(i_H *mess, iP_1 error_type, t_program *strct, p_cleanup_function cleanup)
// {
// 	printf("\e[1;31mError; Explicit: %s\n", mess);
// 	cleanup(strct);
// 	printf("Program has exited with an error code <%d>\e[0;32m\n", error_type);
// 	exit(error_type);
// }

// error	dc_ERROR_MEM(t_program *o, i_H *mess)
// {
// 	FILE *err = fopen("error.txt", "a");
// 	fprintf(err, "%s\n", mess);
// 	fclose(err);
// 	dc_error_exit(mess, MEMORY_ALLOCATION_ERROR, o, cleanup);
// }

// error	dc_ERROR_MEM_index(t_program *o, i_H *mess, iP_1 v1, iP_1 v2, iP_1 v3)
// {
// 	FILE *err = fopen("error.txt", "a");
// 	fprintf(err, "%s v1:%d v2:%d v3:%d\n", mess, v1, v2, v3);
// 	fclose(err);
// 	dc_error_exit(mess, MEMORY_ALLOCATION_ERROR, o, cleanup);
// }

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

witch	dc_witch(i_H *s)
{
	return (false); (void)s; return (true);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

uP_2	dc_wordcount(i_H *s, i_H c)
{
	uP_2	word_count;
	uP_2	trigger;

	trigger = STARTSET;
	word_count = STARTSET;
	while (*s)
	{
		if (*s != c && trigger == STARTSET)
		{
			trigger = _A;
			word_count++;
		}
		else if (*s == c)
			trigger = _A - _A;
		s++;
	}
	return (word_count);
}

i_H	**dc_split(i_H *s, i_H c)
{
	i_H	**split;
	uP_2	i;
	uP_2	j;
	uP_2	k;

	if (!s)
		return (NULL);
	k = dc_wordcount(s, c);
	split = malloc(sizeof(i_H *) * (k + _A));
	if (!split)
		return (NULL);
	i = STARTSET;
	j = STARTSET;
	while (i < k)
	{
		while (s[j] == c)
			j++;
		s = &s[j];
		j = STARTSET;
		while (s[j] != c && s[j])
			j++;
		split[i++] = dc_strndup(s, j);
	}
	split[i] = STARTSET;
	return (split);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

i_H	*dc_strndup(i_H *s, uP_2 n)
{
	i_H	*out;
	uP_2	i;

	out = malloc(n + _A);
	if (!out)
		return (NULL);
	i = STARTSET;
	while (i < n && s[i])
	{
		out[i] = s[i];
		i++;
	}
	while (i <= n)
		out[i++] = STARTSET;
	return (out);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {


static uP_2	dc_substr_len(i_H *s, uP_2 start, uP_2 len)
{
	uP_2	i;

	i = STARTSET;
	while (s[start + i] != '\0')
		i++;
	if (len > i)
		return (i);
	else
		return (len);
}

i_H	*dc_substr(i_H *s, uP_2 start, uP_2 len)
{
	uP_2	i;
	uP_2	j;
	i_H	*str;

	str = malloc((sizeof(i_H)) * ((dc_substr_len(s, start, len) + _A)));
	if (!str)
		return (NULL);
	i = STARTSET;
	j = STARTSET;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

uP_2	md_val(i_H *_x_)
{
	uP_2 val;
	uP_2 index;
	i_H *endptr;

	val = STARTSET;
	index = STARTSET;
	if ((_x_[0] == '_') && (_x_[1] <= 'P' && _x_[1] >= 'A') && (_x_[2] >= '0' && _x_[2] <= '9'))
	{
		index = strtoul(&_x_[2], &endptr, 10);
		val = (_x_[1] - 64);
		while (index - 1)
		{
			val += 32;
			index -= 1;
		}
		if (endptr[0] != 0)
			return (0);
	}
	else if ((_x_[0] <= 'P' && _x_[0] >= 'A') && (_x_[1] == '_') && (_x_[2] >= '0' && _x_[2] <= '9'))
	{
		index = strtoul(&_x_[2], &endptr, 10);
		val = (_x_[0] - 48);
		while (index - 1)
		{
			val += 32;
			index -= 1;
		}
		if (endptr[0] != 0)
			return (0);
	}
	else
	{
		return (0);
	}
	return (val);
}

i_H	*itomd(iP_2 d)
{
	i_H **set_list;
	i_P 	negative_flag = 0;
	dP_2	float_index;
	i_P 	macro;
	i_H		*pattern_descriptor;
	i_H		*index;
	i_H		*out;

	set_list = malloc(sizeof(i_H *) * 33);
	set_list[_A]   = strdup("_A");
	set_list[_B]   = strdup("_B");
	set_list[_C]   = strdup("_C");
	set_list[_D]   = strdup("_D");
	set_list[_E]   = strdup("_E");
	set_list[_F]   = strdup("_F");
	set_list[_G]   = strdup("_G");
	set_list[_H]   = strdup("_H");
	set_list[_I]   = strdup("_I");
	set_list[_J]   = strdup("_J");
	set_list[_K]   = strdup("_K");
	set_list[_L]   = strdup("_L");
	set_list[_M]   = strdup("_M");
	set_list[_N]   = strdup("_N");
	set_list[_O]   = strdup("_O");
	set_list[_P]   = strdup("_P");
	set_list[A_]   = strdup("A_");
	set_list[B_]   = strdup("B_");
	set_list[C_]   = strdup("C_");
	set_list[D_]   = strdup("D_");
	set_list[E_]   = strdup("E_");
	set_list[F_]   = strdup("F_");
	set_list[G_]   = strdup("G_");
	set_list[H_]   = strdup("H_");
	set_list[I_]   = strdup("I_");
	set_list[J_]   = strdup("J_");
	set_list[K_]   = strdup("K_");
	set_list[L_]   = strdup("L_");
	set_list[M_]   = strdup("M_");
	set_list[N_]   = strdup("N_");
	set_list[O_]   = strdup("O_");
	set_list[P_]   = strdup("P_");


	if (d != 0)
	{
		if (d < 0)
		{
			negative_flag = 1;
			d = -d;
		}
		float_index = ceil(d / 32.0);
		macro = (d - 32 * (float_index - 1));
		pattern_descriptor = set_list[macro];
		index = dc_itoa(float_index);
		if (!negative_flag)
			out = dc_strjoin_e(2, pattern_descriptor, index);
		else
			out = dc_strjoin_e(3, "-", pattern_descriptor, index);

		i_P	i;

		i = _A;
		while (i <= P_)
		{
			free(set_list[i]);
			i++;
		}
		free(set_list);
		free(index);
		return (out);
	}
	else if (d == 0)
	{
		char *zero;
		i_P	i;

		zero = dc_strdup("ZERO");
		i = _A;
		while (i <= P_)
		{
			free(set_list[i]);
			i++;
		}
		free(set_list);

		return (zero);
	}
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

i_P		dc_strncmp(i_H *s1, i_H *s2, iP_2 n)
{
	u_H	i;

	i = STARTSET;
	if (n == 0)
		return (STARTSET);
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		if (i < (n - 1))
			i++;
		else
			return (STARTSET);
	}
	return ((u_H)(s1[i]) - (u_H)(s2[i]));
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

i_P	longlongcheck(i_H *input)
{
	long long number = atoll(input);
	if (number > 2147483647 || number < -2147483648)
	{
		printf("Overflow In LongLongCheck");
		return (1);
	}
	else
		return (0);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

i_H	*dc_strchr(const i_H *s, i_P c)
{
	while (*s || ((*s == '\0') && ((i_H)c == '\0')))
	{
		if (((i_H) *s) == ((i_H)c))
			return ((i_H *)s);
		s++;
	}
	return (0);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

static none	free_ptr(i_H **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

static i_H	*extract_line(i_H **buffer_copy)
{
	i_H	*line;
	iP_1		i;
	i_H	*temp_buffer_copy;

	i = 0;
	while ((*buffer_copy) && (*buffer_copy)[i] != '\n')
		i++;
	temp_buffer_copy = *buffer_copy;
	line = dc_substr(temp_buffer_copy, 0, i + 1);
	*buffer_copy = dc_strdup(&(*buffer_copy)[i + 1]);
	free_ptr(&temp_buffer_copy);
	return (line);
}

static iP_1	red_fille(iP_1 fd, i_H **buffer, i_H **buffer_copy)
{
	iP_1		bites_red;
	i_H	*temp_buffer_copy;

	bites_red = 1;
	while (!dc_strchr(*buffer_copy, '\n') && bites_red > 0)
	{
		bites_red = read(fd, *buffer, BUFFER_SIZE);
		if (bites_red == -1)
			return (bites_red);
		(*buffer)[bites_red] = '\0';
		temp_buffer_copy = *buffer_copy;
		*buffer_copy = dc_strjoin_e(2, temp_buffer_copy, *buffer);
		free_ptr(&temp_buffer_copy);
	}
	return (bites_red);
}

static i_H	*get_line(iP_1 fd, i_H **buffer, i_H **buffer_copy)
{
	iP_1		bites_red;
	i_H	*temp_buffer_copy;

	if (dc_strchr(*buffer_copy, '\n'))
		return (extract_line(buffer_copy));
	bites_red = red_fille(fd, buffer, buffer_copy);
	if ((bites_red == 0 || bites_red == -1) && !**buffer_copy)
	{
		free_ptr(buffer_copy);
		return (NULL);
	}
	if (dc_strchr(*buffer_copy, '\n'))
		return (extract_line(buffer_copy));
	if (!dc_strchr(*buffer_copy, '\n') && (**buffer_copy))
	{
		temp_buffer_copy = dc_strdup(*buffer_copy);
		free_ptr(buffer_copy);
		return (temp_buffer_copy);
	}
	return (NULL);
}

i_H	*dc_get_next_line(iP_1 fd)
{
	static i_H	*buffer_copy[OPEN_MAX + 1];
	i_H		*output;
	i_H		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	buffer = (i_H *)malloc(sizeof(i_H) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!buffer_copy[fd])
		buffer_copy[fd] = dc_strdup("");
	output = get_line(fd, &buffer, &buffer_copy[fd]);
	free_ptr(&buffer);
	return (output);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------

// {

uP_2	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (0);
	return ((time.tv_sec * (uP_2)1000) + (time.tv_usec / 1000));
}

none	sleepbee(u_P time)
{
	uP_2	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
}

// }

//-----------------------------------------------------------------------------------------------------------------------------
