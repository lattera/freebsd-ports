# Ports collection makefile for:	lxr
# Date created:				11 Dec 2008
# Whom:					Eygene Ryabinkin
#
# $FreeBSD$
#

PORTNAME=	lxr
PORTVERSION=	0.10.2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/stable/${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rea@FreeBSD.org
COMMENT=	Source code indexer and cross-referencer

BUILD_DEPENDS=	exctags:${PORTSDIR}/devel/ctags \
		swish-e:${PORTSDIR}/www/swish-e \
		p5-File-MMagic>=0:${PORTSDIR}/devel/p5-File-MMagic

PATCH_STRIP=	-p1

USE_PERL5=	yes
NO_BUILD=	yes

OPTIONS=	POSTGRESQL	"Enable PostgreSQL support"		on \
		MYSQL		"Enable MySQL support (untested)"	off

# Name prefix for database tables, indexes, sequences and other stuff.
DB_PREFIX=	lxr

# Installation directory
.if !defined(LXRDIR)
.if defined(APACHE_DATADIR)
LXRTOPDIR=	${APACHE_DATADIR}/data
.else
LXRTOPDIR=	${PREFIX}/www/data
.endif # defined(APACHE_DATADIR)
LXRDIR=	${LXRTOPDIR}/lxr
.endif # !defined(LXRDIR)

PLIST_SUB+=	LXRDIR=${LXRDIR:S!^${PREFIX}/!!}
PLIST_SUB+=	LXRTOPDIR=${LXRTOPDIR:S!^${PREFIX}/!!}
SUB_LIST+=	LXRDIR=${LXRDIR}
SUB_FILES+=	upgrade-0.9.10-postgres upgrade-0.9.10-mysql

.include <bsd.port.pre.mk>

.if defined(WITH_POSTGRESQL) && defined(WITH_MYSQL)
IGNORE=		you must choose only one database backend
.endif

.if defined(WITH_POSTGRESQL)
BUILD_DEPENDS+=	p5-DBD-Pg>=0:${PORTSDIR}/databases/p5-DBD-Pg
MSG_FILES+=	pkg_message.postgresql
DB_DRIVER=	Pg
.endif # defined(WITH_POSTGRESQL)

.if defined(WITH_MYSQL)
BUILD_DEPENDS+=	p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql
MSG_FILES+=	pkg_message.mysql
DB_DRIVER=	mysql
.endif # defined(WITH_MYSQL)

MSG_FILES+=	pkg_message

SUB_FILES+=	${MSG_FILES}

LXR_SCRIPTS=	diff \
		genxref \
		ident \
		search \
		source

LXR_CONF=	swish-e.conf \
		initdb-postgres \
		initdb-mysql

LXR_DOCS=	BUGS \
		CREDITS.txt \
		ChangeLog \
		HACKING \
		INSTALL \
		LICENSE \
		RELEASING

post-patch:
	@${REINPLACE_CMD} \
	    -e"s|'glimpsebin'|# 'glimpsebin'|" \
	    -e"s|'glimpseindex'|# 'glimpseindex'|" \
	    -e"s|'/usr/local/bin/swish-e'|'${LOCALBASE}/bin/swish-e'|" \
	    -e"s|'/usr/bin/ctags'|'${LOCALBASE}/bin/exctags'|" \
	    -e"s|'/path/to/lib/LXR/Lang/generic.conf'|'${SITE_PERL}/LXR/Lang/generic.conf'|" \
	    -e"s|'/path/to/lib/LXR/Lang/ectags.conf'|'${SITE_PERL}/LXR/Lang/ectags.conf'|" \
	    -e"s|'dbi:mysql:|'dbi:${DB_DRIVER}:|" \
	    -e's|'lxr_'|'${DB_PREFIX}_'|g' \
	    ${WRKSRC}/templates/lxr.conf && \
	    ${RM} -f ${WRKSRC}/templates/lxr.conf.bak
	@${REINPLACE_CMD} \
	    -e's|lxr_|${DB_PREFIX}_|g' \
	    ${WRKSRC}/initdb-postgres
	@${REINPLACE_CMD} \
	    -e's|lxr|${DB_PREFIX}|g' \
	    ${WRKSRC}/initdb-mysql

do-install:
	${MKDIR} ${LXRDIR}
.for f in ${LXR_SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${LXRDIR}
.endfor # ${LXR_SCRIPTS}
.for f in ${LXR_CONF}
	${INSTALL_DATA} ${WRKSRC}/${f} ${LXRDIR}
.endfor # ${LXR_CONF}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${LXR_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor # ${LXR_DOCS}
.endif # !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${SITE_PERL_REL}
	${INSTALL_DATA} ${WRKSRC}/Local.pm ${PREFIX}/${SITE_PERL_REL}
	${INSTALL_DATA} ${WRKSRC}/LXRversion.pm ${PREFIX}/${SITE_PERL_REL}
	${TAR} -C ${WRKSRC}/lib -cf - --exclude '*.orig' LXR | ${TAR} -C ${PREFIX}/${SITE_PERL_REL} -xf -
	${TAR} -C ${WRKSRC} -cf - --exclude '*.orig' templates | ${TAR} -C ${LXRDIR} -xf -
	${CHMOD} 640 ${LXRDIR}/templates/lxr.conf
	${INSTALL_DATA} ${WRKDIR}/upgrade-0.9.10-postgres ${LXRDIR}
	${INSTALL_DATA} ${WRKDIR}/upgrade-0.9.10-mysql ${LXRDIR}

post-install:
	@${ECHO}
	@${ECHO} "******************** Installation tips ********************"
	@${ECHO}
.for f in ${MSG_FILES}
	@${CAT} ${WRKDIR}/${f}
.endfor # ${MSG_FILES}

.include <bsd.port.post.mk>
