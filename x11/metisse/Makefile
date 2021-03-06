# New ports collection makefile for:	Metisse
# Date created:				31 May 2007
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	metisse
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://insitu.lri.fr/metisse/download/metisse/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	An innovative X-based window system

LICENSE=	GPLv3

CONFLICTS=	fvwm-1.* fvwm-2.5.*

LIB_DEPENDS=	Nucleo.0:${PORTSDIR}/x11-toolkits/nucleo \
		png15:${PORTSDIR}/graphics/png
RUN_DEPENDS=	${LOCALBASE}/libdata/xorg/fonts:${PORTSDIR}/x11-fonts/xorg-fonts

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libpng15
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-fontdir=${LOCALBASE}/lib/X11/fonts
MAKE_ARGS=	METISSE_DOC_DIR="${DOCSDIR}"
USE_GETTEXT=	yes
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes
USE_PYTHON=	yes
USE_XORG=	xcursor xft xinerama xpm xrender xt xtst

OPTIONS=	MMX	"Enable MMX optimizations"		on \
		GLX	"Enable GLX extension"			on \
		GLX_X86	"Build GLX with x86 optimizations"	on \
		ATSPI	"Enable widget tracking support"	off \
		STROKE	"Enable support for mouse gestures"	off \
		RPLAY	"Enable RPlay support in FvwmEvent"	off \
		BIDI	"Enable bi-directional text support"	off \
		GLIB	"Use GLib 2.x for module integration"	off \
		GTK2	"Use GDK-PixBuf-2.0 for image loading"	off \
		GCONF	"Enable GConf/Glade configuration UI"	off \
		GTK1	"Enable legacy GTK+ 1.2.x support"	off \
		IMLIB	"Enable Imlib support in FvwmGtk"	off \
		GNOME	"Enable legacy GNOME 1.4 support"	off

.include <bsd.port.pre.mk>

.if ${MACHINE_CPU:Mmmx} && !defined(WITHOUT_MMX)
CONFIGURE_ARGS+=	--enable-mmx
.endif

.if !defined(WITHOUT_GLX)
CONFIGURE_ARGS+=	--enable-glx
.endif

.if ${ARCH} == "i386" && !defined(WITHOUT_GLX_X86)
CONFIGURE_ARGS+=	--enable-glx-x86
.endif

.if defined(WITH_ATSPI)
USE_GNOME+=	atspi
.endif

.if defined(WITH_STROKE)
LIB_DEPENDS+=	stroke.0:${PORTSDIR}/devel/libstroke
.endif

.if defined(WITH_RPLAY)
LIB_DEPENDS+=	rplay.1:${PORTSDIR}/audio/rplay
.endif

.if defined(WITH_BIDI)
LIB_DEPENDS+=	fribidi.3:${PORTSDIR}/converters/fribidi
.endif

.if ${HAVE_GNOME:Mglib20} || defined(WITH_GLIB)
USE_GNOME+=	glib20
.endif

.if ${HAVE_GNOME:Mgtk20} || defined(WITH_GTK2)
USE_GNOME+=	gtk20
.endif

.if ${HAVE_GNOME:Mgconf2} && ${HAVE_GNOME:Mlibglade2} || defined(WITH_GCONF)
USE_GNOME+=	gconf2 libglade2
PLIST_SUB+=	GCONF=""
.else
_NOGLADEDIR=	yes
PLIST_SUB+=	GCONF="@comment "
.endif

.if ${HAVE_GNOME:Mgtk12} || defined(WITH_GTK1)
USE_GNOME+=	gtk12
.endif

.if ${HAVE_GNOME:Mimlib} || defined(WITH_IMLIB)
USE_GNOME+=	imlib
.endif

.if ${HAVE_GNOME:Mgnomelibs} || defined(WITH_GNOME)
USE_GNOME+=	gnomelibs
.endif

MAN1=	FvwmAnimate.1 FvwmAuto.1 FvwmBacker.1 FvwmBanner.1 FvwmButtons.1 \
	FvwmCommand.1 FvwmConsole.1 FvwmConsoleC.pl.1 FvwmCpp.1 FvwmDebug.1 \
	FvwmDragWell.1 FvwmEvent.1 FvwmForm.1 FvwmGtkDebug.1 FvwmIconBox.1 \
	FvwmIconMan.1 FvwmIdent.1 FvwmM4.1 FvwmPager.1 FvwmPerl.1 \
	FvwmProxy.1 FvwmRearrange.1 FvwmSave.1 FvwmSaveDesk.1 FvwmScript.1 \
	FvwmScroll.1 FvwmTabs.1 FvwmTaskBar.1 FvwmTheme.1 FvwmWharf.1 \
	FvwmWinList.1 FvwmWindowMenu.1 fvwm-bug.1 fvwm-config.1 \
	fvwm-convert-2.4.1 fvwm-convert-2.6.1 fvwm-menu-desktop.1 \
	fvwm-menu-directory.1 fvwm-menu-headlines.1 fvwm-menu-xlock.1 \
	fvwm-perllib.1 fvwm-root.1 fvwm.1

_GTK=	${USE_GNOME:Mgtk12} ${USE_GNOME:Mimlib}
.if !empty(_GTK)
MAN1+=		FvwmGtk.1
PLIST_SUB+=	GTK=""
.else
PLIST_SUB+=	GTK="@comment "
.endif

post-patch: .SILENT
# Catch up with new <fribidi-types.h> header name
	${REINPLACE_CMD} -e 's,fribidi_types\.h,fribidi-types.h,' \
		${WRKSRC}/fvwm-insitu/libs/FBidi.c
# Fix desktop entries path
	${REINPLACE_CMD} -E 's,^(configdir =).*,\1 ${DESKTOPDIR},' \
		${WRKSRC}/fvwm-insitu/opale/session/Makefile.in
.if defined(_NOGLADEDIR)
	${REINPLACE_CMD} -e 's, install-gladeDATA,,' \
		${WRKSRC}/fvwm-insitu/modules/FvwmConfig/Makefile.in
.endif

.include <bsd.port.post.mk>
