/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:49:17 by tliangso          #+#    #+#             */
/*   Updated: 2022/10/11 11:17:43 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTING_H
# define SETTING_H

# define WIDTH 900
# define HEIGHT 900

# define JULIA 1
# define MANDELBOT 2
# define BURNINGSHIP 3
# define TRICORN 4
# define MANDELBOX 5

# ifndef MAXINTER
#  define MAXINTER 60
# endif
# if MAXINTER > 100 || MAXINTER < 1
#  undef MAXINTER
#  define MAXINTER 60
# endif

# ifndef SIZE_MAX
/* Limit of `size_t' type.  */
#  if __WORDSIZE == 64
#   define SIZE_MAX                (18446744073709551615UL)
#  else
#   define SIZE_MAX                (4294967295U)
#  endif
# endif

#endif
