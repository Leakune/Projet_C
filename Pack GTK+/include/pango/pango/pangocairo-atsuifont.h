/* Pango
 * pangocairo-atsuifont.c
 *
 * Copyright (C) 2005 Imendio AB
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef __PANGOCAIRO_ATSUIFONT_H__
#define __PANGOCAIRO_ATSUIFONT_H__

#define PANGO_TYPE_CAIRO_ATSUI_FONT           (pango_cairo_atsui_font_get_type ())
#define PANGO_CAIRO_ATSUI_FONT(object)        (G_TYPE_CHECK_INSTANCE_CAST ((object), PANGO_TYPE_CAIRO_ATSUI_FONT, PangoCairoATSUIFont))
#define PANGO_CAIRO_ATSUI_FONT_CLASS(klass)   (G_TYPE_CHECK_CLASS_CAST ((klass), PANGO_TYPE_CAIRO_ATSUI_FONT, PangoCairoATSUIFontClass))
#define PANGO_CAIRO_IS_FONT_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), PANGO_TYPE_CAIRO_ATSUI_FONT))
#define PANGO_CAIRO_ATSUI_FONT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), PANGO_TYPE_CAIRO_ATSUI_FONT, PangoCairoATSUIFontClass))

typedef struct _PangoCairoATSUIFont      PangoCairoATSUIFont;
typedef struct _PangoCairoATSUIFontClass PangoCairoATSUIFontClass;

GType pango_cairo_atsui_font_get_type (void);

ATSUFontID pango_cairo_atsui_font_get_atsu_font_id (PangoCairoATSUIFont *cafont);

#endif /* __PANGOCAIRO_ATSUIFONT_H__ */
