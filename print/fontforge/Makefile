# New ports collection makefile for:	fontforge
# Date created:		25 March 2001
# Whom:			KANOU Hiroki <kanou@khdd.net>
#
# $FreeBSD$
#

PORTNAME=	fontforge
DISTVERSION=	20120731-b
CATEGORIES=	print
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-source
DISTFILES=	${EXTRACT_ONLY}
EXTRACT_ONLY=	${PORTNAME}_full-${DISTVERSION}.tar.bz2

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Type 1/TrueType/OpenType/bitmap font editor

LIB_DEPENDS=	uninameslist:${PORTSDIR}/textproc/libuninameslist \
		tiff:${PORTSDIR}/graphics/tiff \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		gif:${PORTSDIR}/graphics/giflib \
		freetype:${PORTSDIR}/print/freetype2 \
		xml2:${PORTSDIR}/textproc/libxml2 \
		spiro:${PORTSDIR}/graphics/libspiro

.if defined(FONTFORGE_WITH_TTF_DEBUGGER)
FREETYPE_VERSION=	2.4.9
EXTRACT_ONLY+=	freetype-${FREETYPE_VERSION}.tar.bz2
.endif

.if !defined(NOPORTDOCS)
DOC_VERSION=	${DISTVERSION}
MASTER_SITES+=	SF/${PORTNAME}/${PORTNAME}-docs:docs
DOCFILES=	${PORTNAME}_htdocs-${DOC_VERSION}.tar.bz2
DISTFILES+=	${DOCFILES:C/$/:docs/}
.endif

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_XORG=	x11 xi ice xkbfile
USE_GMAKE=	yes
USE_ICONV=	yes
PATCH_STRIP=	-l

.if !defined(FONTFORGE_NO_MULTILAYER)
WITH_MULTILAYER=	--enable-type3
.else
WITH_MULTILAYER=	--disable-type3
.endif

.if !defined(WITHOUT_TTF_BYTECODE_ENABLED) && defined(FONTFORGE_WITH_TTF_DEBUGGER)
WITH_FREETYPE_SRC=	--enable-freetype --with-freetype-bytecode \
			--with-freetype-src=${WRKDIR}/freetype-${FREETYPE_VERSION}
.else
WITH_FREETYPE_SRC=	--disable-freetype --without-freetype-bytecode \
			--without-freetype-src
.endif

CONFIGURE_ARGS=	${WITH_MULTILAYER} --enable-devicetables ${WITH_FREETYPE_SRC} \
		--enable-pasteafter --enable-tilepath
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool

MAN1=		fontforge.1 fontimage.1 fontlint.1 sfddiff.1

.if defined(FONTFORGE_NO_PLUGINS)
PLIST_SUB+=	NO_PLUGINS="@comment "
.else
PLIST_SUB+=	NO_PLUGINS=""
.endif

.if defined(WITH_PYTHON)
USE_PYTHON=	yes
ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	Python on non-i386 systems doesn't link with Fontforge (issues with use of Python's .a file)
CONFIGURE_ARGS+=	--with-python
LDFLAGS+=	-lutil
.else
CONFIGURE_ARGS+=	--without-python
.endif

.if defined(WITH_CAIRO)
LIB_DEPENDS+=	cairo:${PORTSDIR}/graphics/cairo
CONFIGURE_ARGS+=	--with-cairo
.else
CONFIGURE_ARGS+=	--without-cairo
.endif

.if defined(WITH_PANGO)
USE_GNOME+=	pango
CONFIGURE_ARGS+=	--with-pango
.else
CONFIGURE_ARGS+=	--without-pango
.endif

pre-everything::
.if !defined(WITHOUT_TTF_BYTECODE_ENABLED) && !defined(FONTFORGE_WITH_TTF_DEBUGGER)
	@${ECHO_MSG} "If you have built freetype2 port with bytecode interpreter enabled,"
	@${ECHO_MSG} "You can use TTF instruction debugger by compiling fontforge port"
	@${ECHO_MSG} "with FONTFORGE_WITH_TTF_DEBUGGER defined."
	@${ECHO_MSG} "Note that you must put the source archive of FreeType in ${DISTDIR}."
	@${ECHO_MSG} "If you have installed freetype2 from a package, chdir to ${PORTSDIR}/print/freetype2"
	@${ECHO_MSG} "and execute 'make fetch' before building this port".
	@${ECHO_MSG} ""
.endif
.if !defined(FONTFORGE_NO_MULTILAYER)
	@${ECHO_MSG} "If your machine has small memory and you have to edit fonts with a lot"
	@${ECHO_MSG} "of glyphs, you can save memory by defining FONTFORGE_NO_MULTILAYER."
	@${ECHO_MSG} "Enabling multilayer editing increases memory consumption per glyph."
	@${ECHO_MSG} ""
.endif

.if !defined(NOPORTDOCS)
post-extract:
	${MKDIR} ${WRKDIR}/html ${WRKSRC}/cidmap
	for doc in ${DOCFILES} ; \
		do ${TAR} -xjC ${WRKDIR}/html -f ${DISTDIR}/$${doc} ; \
	done
# The 20080607 and up versions of fontforge's documentation doesn't contain the cidmaps,
#  but I'm leaving this here just in case they are added back in a later version.
#	${TAR} -xzC ${WRKSRC}/cidmap -f ${WRKDIR}/html/cidmaps.tgz
#	${RM} ${WRKDIR}/html/cidmaps.tgz
.endif

post-patch:
	@${CHMOD} +x ${WRKSRC}/configure

.if !defined(FONTFORGE_NO_PLUGINS)
post-build:
	cd ${WRKSRC}/plugins; ${GMAKE}
.endif

post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}
.if !defined(FONTFORGE_NO_PLUGINS)
	${MKDIR} ${PREFIX}/share/fontforge/plugins
	(cd ${WRKSRC}/plugins; ${INSTALL_DATA} .libs/* ${PREFIX}/share/fontforge/plugins )
.endif
.if !defined(NOPORTDOCS)
# Ditto the above note in post-extract for these comments
#	${MKDIR} ${DOCSDIR}/flags
	${INSTALL_DATA} ${WRKDIR}/html/*.* ${DOCSDIR}
#	${INSTALL_DATA} ${WRKDIR}/html/flags/*.* ${DOCSDIR}/flags
.endif

.include <bsd.port.mk>
