# New ports collection makefile for:	libxml2
# Date created:				28 September 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#
# WITHOUT_SCHEMA disable XML schema support
# WITHOUT_THREADS disable threads support
# WITH_MEM_DEBUG enable memory debugging (DEVELOPERS ONLY!)
# WITH_XMLLINT_HIST enable history for xmllint
# WITH_THREAD_ALLOC enable per-thread memory (DEVELOPERS ONLY!)
#

PORTNAME=	libxml2
PORTVERSION=	2.7.8
PORTREVISION?=	5
CATEGORIES?=	textproc gnome
MASTER_SITES=	ftp://gd.tuwien.ac.at/pub/libxml/ \
		ftp://xmlsoft.org/libxml2/
DIST_SUBDIR=	gnome2

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	XML parser library for GNOME

.if !defined(REFERENCE_PORT)

USE_CSTD=	gnu89
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
GNU_CONFIGURE=	yes
USE_GNOME?=	gnomehack pkgconfig
USE_LDCONFIG=	yes
CONFIGURE_ARGS?=--with-html-dir=${PREFIX}/share/doc \
		--with-html-subdir=${PORTNAME} \
		--without-python
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.if !defined(WITHOUT_ICONV)
USE_ICONV=	yes
CONFIGURE_ARGS+=--with-iconv=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-iconv=no
.endif

.if !defined(MASTERDIR)
MAN1=		xml2-config.1 xmllint.1 xmlcatalog.1
MAN3=		libxml.3
.endif

.if defined(WITHOUT_SCHEMA)
CONFIGURE_ARGS+=	--without-schemas
.endif

.if defined(WITHOUT_THREADS)
CONFIGURE_ARGS+=	--without-threads
.endif

.if defined(WITH_MEM_DEBUG)
CONFIGURE_ARGS+=	--with-mem-debug
.endif

.if defined(WITH_XMLLINT_HIST)
CONFIGURE_ARGS+=	--with-history
.endif

.if defined(WITH_THREAD_ALLOC)
CONFIGURE_ARGS+=	--with-thread-alloc
.endif

post-patch:
.for d in . doc doc/devhelp doc/examples
	@${REINPLACE_CMD} -e '/^install-data-am:/ s|install-data-local||' \
		${WRKSRC}/${d}/Makefile.in
.endfor
.for f in catalog.c xmlcatalog.c xmllint.c doc/xmllint.1
	@${REINPLACE_CMD} -e \
		's|/etc/xml/catalog|${LOCALBASE}/share/xml/catalog|g; \
		 s|/etc/sgml/catalog|${LOCALBASE}/share/sgml/catalog|g' ${WRKSRC}/${f}
.endfor
# manual patch because WITH_FBSD10_FIX break the python bindings
	${FIND} ${WRKSRC} -type f -name configure \
		-exec ${SH} -c " \
		mtime=\$$(date -r \$$(stat -f '%m' \$$0) '+%Y%m%d%H%M.%S'); \
		${SED} -i '.batman' -e 's|freebsd1\*)|freebsd1.\*)|g' \
		-e 's|freebsd\[123\]\*)|freebsd[123].*)|g' \$$0; \
		touch -mt \$$mtime \$$0" {} \; || /usr/bin/true

.include <bsd.port.mk>

.endif
