# New ports collection makefile for:	squirrelmail
# Date created: 			27 December 2001
# Whom: 				Simon Dick <simond@irrelevant.org>
#
# $FreeBSD$
#

PORTNAME=	squirrelmail
PORTVERSION=	1.4.22
CATEGORIES=	mail www
MASTER_SITES=	SF/${PORTNAME}/stable/${PORTVERSION:S/.r/-RC/}:squirrelmail \
		SF/${PORTNAME}/locales/1.4.18-20090526:locales
DISTNAME=	${PORTNAME}-webmail-${PORTVERSION:S/.r/-RC/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:squirrelmail \
		all_locales-1.4.18-20090526${EXTRACT_SUFX}:locales
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	A webmail system which accesses mail over IMAP

USE_PHP=	session mhash gettext mbstring pcre openssl xml
WANT_PHP_WEB=	yes
IGNORE_WITH_PHP=5 # known incompatibilities with php-5.4, use 5.3 for now

USE_BZIP2=	yes
USE_GETTEXT=	yes

OPTIONS_DEFINE=	DATABASE LDAP
DATABASE_DESC=	PEAR database support (must also intall a driver)

# if you were using WITHOUT_WWWDIR, use SQUIRRELDIR=${PREFIX}/${PORTNAME}
SQUIRRELDIR?=	${PREFIX}/www/${PORTNAME}

SMUSER?=	${WWWOWN}
SMGROUP?=	${WWWGRP}
USERS=		${SMUSER}
GROUPS=		${SMGROUP}

PLIST_SUB=	PORTVERSION=${PORTVERSION} \
		SQUIRRELDIR="${SQUIRRELDIR:S,^${PREFIX}/,,}"

SUB_FILES=	pkg-message pkg-install pkg-deinstall
SUB_LIST=	SQUIRRELDIR=${SQUIRRELDIR} SMUSER=${SMUSER} SMGROUP=${SMGROUP}

PORTDOCS=	*

CONFLICTS=	squirreloutlook-[0-9]*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDATABASE}
RUN_DEPENDS+=	${LOCALBASE}/share/pear/DB.php:${PORTSDIR}/databases/pear-DB
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_PHP+=	ldap
.endif

pre-everything::
.if ${PORT_OPTIONS:MDATABASE}
	@${ECHO_CMD} "Note that the PEAR database framework still requires you to install a"
	@${ECHO_CMD} "database-specific PEAR driver, e.g. MySQL."
	@${ECHO_CMD}
.endif

post-patch:
.ifndef PATCH_DEBUG
	@${RM} -f \
		${WRKSRC}/class/deliver/Deliver.class.php.orig \
		${WRKSRC}/config/config_default.php.orig \
		${WRKSRC}/functions/global.php.orig \
		${WRKSRC}/functions/i18n.php.orig \
		${WRKSRC}/functions/imap_search.php.orig \
		${WRKSRC}/src/addrbook_search_html.php.orig \
		${WRKSRC}/src/compose.php.orig
.endif
	@${REINPLACE_CMD} -e 's|ispell|${LOCALBASE}/bin/ispell|g' \
		${WRKSRC}/plugins/squirrelspell/sqspell_config.php
	@${REINPLACE_CMD} -e 's|/usr/bin/fortune|/usr/games/fortune|g' \
		${WRKSRC}/plugins/fortune/fortune_functions.php
	@${RM} ${WRKSRC}/plugins/squirrelspell/sqspell_config.php.bak \
		${WRKSRC}/plugins/fortune/fortune_functions.php.bak

# Rearrange the documentation
do-build:
	@${MV} ${WRKSRC}/themes/README.themes ${WRKSRC}/doc/
	@cd ${WRKSRC} ; for f in `find plugins -name "README*" -or \
		-name INSTALL -or -name CHANGES -or -name HISTORY`; \
		do \
		${MKDIR} doc/`dirname $$f` ; \
		${MV} $$f doc/`dirname $$f` ; \
	done; \
	${MV} doc/plugins/squirrelspell/doc/README doc/plugins/squirrelspell ; \
	${RM} -rf doc/plugins/squirrelspell/doc ; \
	${MV} plugins/squirrelspell/doc/* doc/plugins/squirrelspell ; \
	${RM} -f doc/plugins/squirrelspell/index.php ; \
	${RM} -rf plugins/squirrelspell/doc
	@${ECHO} "left_refresh=300" >> ${WRKSRC}/data/default_pref
	@${CP} -r ${WRKSRC}/../locale ${WRKSRC}
	@${CP} -r ${WRKSRC}/../images ${WRKSRC}
	@${CP} -r ${WRKSRC}/../help ${WRKSRC}
	@${MV} ${WRKSRC}/config/config_local.php ${WRKSRC}/config/config_local.php.sample

pre-install:
	@${ECHO} "Your umask should be lax while installing this. Like, 022 or something."
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	${MKDIR} ${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${FILESDIR}/111.clean-squirrelmail ${PREFIX}/etc/periodic/daily
	${MKDIR} ${SQUIRRELDIR}
	@${CP} -pv ${WRKSRC}/index.php ${SQUIRRELDIR}
	@${CP} -pv ${WRKSRC}/configure ${SQUIRRELDIR}
.for DIR in class config data functions help images include locale plugins po src themes
	@${CP} -rpv ${WRKSRC}/${DIR} ${SQUIRRELDIR}
.endfor
	${CHOWN} -R ${SMUSER}:${SMGROUP} ${SQUIRRELDIR}/data
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@${CP} -Rv ${WRKSRC}/doc/* ${DOCSDIR}
.endif

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
