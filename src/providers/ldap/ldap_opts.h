/*
    SSSD

    Authors:
        Stephen Gallagher <sgallagh@redhat.com>

    Copyright (C) 2012 Red Hat

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef LDAP_OPTS_H_
#define LDAP_OPTS_H_

#include "src/providers/data_provider.h"
#include "db/sysdb.h"
#include "db/sysdb_sudo.h"
#include "db/sysdb_autofs.h"
#include "db/sysdb_services.h"

struct dp_option default_basic_opts[] = {
    { "ldap_uri", DP_OPT_STRING, NULL_STRING, NULL_STRING },
    { "ldap_search_base", DP_OPT_STRING, NULL_STRING, NULL_STRING },
    { "ldap_default_bind_dn", DP_OPT_STRING, NULL_STRING, NULL_STRING },
    { "ldap_default_authtok_type", DP_OPT_STRING, { "password" }, NULL_STRING},
    { "ldap_default_authtok", DP_OPT_BLOB, NULL_BLOB, NULL_BLOB },
    { "ldap_search_timeout", DP_OPT_NUMBER, { .number = 6 }, NULL_NUMBER },
    { "ldap_network_timeout", DP_OPT_NUMBER, { .number = 6 }, NULL_NUMBER },
    { "ldap_opt_timeout", DP_OPT_NUMBER, { .number = 6 }, NULL_NUMBER },
    { "ldap_tls_reqcert", DP_OPT_STRING, { "hard" }, NULL_STRING },
    { "ldap_user_search_base", DP_OPT_STRING, NULL_STRING, NULL_STRING },
    { "ldap_user_search_scope", DP_OPT_STRING, { "sub" }, NULL_STRING },
    { "ldap_user_search_filter", DP_OPT_STRING, NULL_STRING, NULL_STRING },
    { "ldap_group_search_base", DP_OPT_STRING, NULL_STRING, NULL_STRING },
    { "ldap_group_search_scope", DP_OPT_STRING, { "sub" }, NULL_STRING },
    { "ldap_group_search_filter", DP_OPT_STRING, NULL_STRING, NULL_STRING },
    { "ldap_service_search_base", DP_OPT_STRING, NULL_STRING, NULL_STRING },
    { "ldap_sudo_search_base", DP_OPT_STRING, NULL_STRING, NULL_STRING },
    { "ldap_sudo_full_refresh_interval", DP_OPT_NUMBER, { .number = 21600 }, NULL_NUMBER }, /* 360 mins */
    { "ldap_autofs_search_base", DP_OPT_STRING, NULL_STRING, NULL_STRING },
    { "ldap_schema", DP_OPT_STRING, { "rfc2307" }, NULL_STRING },
    { "ldap_offline_timeout", DP_OPT_NUMBER, { .number = 60 }, NULL_NUMBER },
    { "ldap_force_upper_case_realm", DP_OPT_BOOL, BOOL_FALSE, BOOL_FALSE },
    { "ldap_enumeration_refresh_timeout", DP_OPT_NUMBER, { .number = 300 }, NULL_NUMBER },
    { "ldap_purge_cache_timeout", DP_OPT_NUMBER, { .number = 10800 }, NULL_NUMBER },
    { "ldap_tls_cacert", DP_OPT_STRING, NULL_STRING, NULL_STRING },
    { "ldap_tls_cacertdir", DP_OPT_STRING, NULL_STRING, NULL_STRING },
    { "ldap_tls_cert", DP_OPT_STRING, NULL_STRING, NULL_STRING },
    { "ldap_tls_key", DP_OPT_STRING, NULL_STRING, NULL_STRING },
    { "ldap_tls_cipher_suite", DP_OPT_STRING, NULL_STRING, NULL_STRING },
    { "ldap_id_use_start_tls", DP_OPT_BOOL, BOOL_FALSE, BOOL_FALSE },
    { "ldap_id_mapping", DP_OPT_BOOL, BOOL_FALSE, BOOL_FALSE },
    { "ldap_sasl_mech", DP_OPT_STRING, NULL_STRING, NULL_STRING },
    { "ldap_sasl_authid", DP_OPT_STRING, NULL_STRING, NULL_STRING },
    { "ldap_sasl_realm", DP_OPT_STRING, NULL_STRING, NULL_STRING },
    { "ldap_sasl_minssf", DP_OPT_NUMBER, { .number = -1 }, NULL_NUMBER },
    { "ldap_krb5_keytab", DP_OPT_STRING, NULL_STRING, NULL_STRING },
    { "ldap_krb5_init_creds", DP_OPT_BOOL, BOOL_TRUE, BOOL_TRUE },
    /* use the same parm name as the krb5 module so we set it only once */
    { "krb5_server", DP_OPT_STRING, NULL_STRING, NULL_STRING },
    { "krb5_realm", DP_OPT_STRING, NULL_STRING, NULL_STRING },
    { "krb5_canonicalize", DP_OPT_BOOL, BOOL_TRUE, BOOL_TRUE },
    { "ldap_pwd_policy", DP_OPT_STRING, { "none" }, NULL_STRING },
    { "ldap_referrals", DP_OPT_BOOL, BOOL_TRUE, BOOL_TRUE },
    { "account_cache_expiration", DP_OPT_NUMBER, { .number = 0 }, NULL_NUMBER },
    { "ldap_dns_service_name", DP_OPT_STRING, { SSS_LDAP_SRV_NAME }, NULL_STRING },
    { "ldap_krb5_ticket_lifetime", DP_OPT_NUMBER, { .number = (24 * 60 * 60) }, NULL_NUMBER },
    { "ldap_access_filter", DP_OPT_STRING, NULL_STRING, NULL_STRING },
    { "ldap_netgroup_search_base", DP_OPT_STRING, NULL_STRING, NULL_STRING },
    { "ldap_group_nesting_level", DP_OPT_NUMBER, { .number = 2 }, NULL_NUMBER },
    { "ldap_deref", DP_OPT_STRING, NULL_STRING, NULL_STRING },
    { "ldap_account_expire_policy", DP_OPT_STRING, NULL_STRING, NULL_STRING },
    { "ldap_access_order", DP_OPT_STRING, { "filter" }, NULL_STRING },
    { "ldap_chpass_uri", DP_OPT_STRING, NULL_STRING, NULL_STRING },
    { "ldap_chpass_dns_service_name", DP_OPT_STRING, NULL_STRING, NULL_STRING },
    { "ldap_chpass_update_last_change", DP_OPT_BOOL, BOOL_FALSE, BOOL_FALSE },
    { "ldap_enumeration_search_timeout", DP_OPT_NUMBER, { .number = 60 }, NULL_NUMBER },
    /* Do not include ldap_auth_disable_tls_never_use_in_production in the
     * manpages or SSSDConfig API
     */
    { "ldap_auth_disable_tls_never_use_in_production", DP_OPT_BOOL, BOOL_FALSE, BOOL_FALSE },
    { "ldap_page_size", DP_OPT_NUMBER, { .number = 1000 }, NULL_NUMBER },
    { "ldap_deref_threshold", DP_OPT_NUMBER, { .number = 10 }, NULL_NUMBER },
    { "ldap_sasl_canonicalize", DP_OPT_BOOL, BOOL_FALSE, BOOL_FALSE },
    { "ldap_connection_expire_timeout", DP_OPT_NUMBER, { .number = 900 }, NULL_NUMBER },
    { "ldap_disable_paging", DP_OPT_BOOL, BOOL_FALSE, BOOL_FALSE },
    { "ldap_idmap_range_min", DP_OPT_NUMBER, { .number = 100001 }, NULL_NUMBER },
    { "ldap_idmap_range_max", DP_OPT_NUMBER, { .number = 2000100000LL }, NULL_NUMBER },
    { "ldap_idmap_range_size", DP_OPT_NUMBER, { .number = 200000 }, NULL_NUMBER },
    { "ldap_idmap_autorid_compat", DP_OPT_BOOL, BOOL_FALSE, BOOL_FALSE },
    { "ldap_idmap_default_domain", DP_OPT_STRING, NULL_STRING, NULL_STRING },
    { "ldap_idmap_default_domain_sid", DP_OPT_STRING, NULL_STRING, NULL_STRING },
    { "ldap_groups_use_matching_rule_in_chain", DP_OPT_BOOL, BOOL_FALSE, BOOL_FALSE },
    { "ldap_initgroups_use_matching_rule_in_chain", DP_OPT_BOOL, BOOL_TRUE, BOOL_FALSE },
    DP_OPTION_TERMINATOR
};

struct sdap_attr_map generic_attr_map[] = {
    { "ldap_entry_usn", NULL, SYSDB_USN, NULL },
    { "ldap_rootdse_last_usn", NULL, SYSDB_HIGH_USN, NULL },
    SDAP_ATTR_MAP_TERMINATOR
};

struct sdap_attr_map gen_ipa_attr_map[] = {
    { "ldap_entry_usn", SDAP_IPA_USN, SYSDB_USN, NULL },
    { "ldap_rootdse_last_usn", SDAP_IPA_LAST_USN, SYSDB_HIGH_USN, NULL },
    SDAP_ATTR_MAP_TERMINATOR
};

struct sdap_attr_map gen_ad_attr_map[] = {
    { "ldap_entry_usn", SDAP_AD_USN, SYSDB_USN, NULL },
    { "ldap_rootdse_last_usn", SDAP_AD_LAST_USN, SYSDB_HIGH_USN, NULL },
    SDAP_ATTR_MAP_TERMINATOR
};

struct sdap_attr_map rfc2307_user_map[] = {
    { "ldap_user_object_class", "posixAccount", SYSDB_USER_CLASS, NULL },
    { "ldap_user_name", "uid", SYSDB_NAME, NULL },
    { "ldap_user_pwd", "userPassword", SYSDB_PWD, NULL },
    { "ldap_user_uid_number", "uidNumber", SYSDB_UIDNUM, NULL },
    { "ldap_user_gid_number", "gidNumber", SYSDB_GIDNUM, NULL },
    { "ldap_user_gecos", "gecos", SYSDB_GECOS, NULL },
    { "ldap_user_home_directory", "homeDirectory", SYSDB_HOMEDIR, NULL },
    { "ldap_user_shell", "loginShell", SYSDB_SHELL, NULL },
    { "ldap_user_principal", "krbPrincipalName", SYSDB_UPN, NULL },
    { "ldap_user_fullname", "cn", SYSDB_FULLNAME, NULL },
    { "ldap_user_member_of", NULL, SYSDB_MEMBEROF, NULL },
    { "ldap_user_uuid", NULL, SYSDB_UUID, NULL },
    { "ldap_user_objectsid", NULL, SYSDB_SID, NULL },
    { "ldap_user_primary_group", NULL, SYSDB_PRIMARY_GROUP, NULL },
    { "ldap_user_modify_timestamp", "modifyTimestamp", SYSDB_ORIG_MODSTAMP, NULL },
    { "ldap_user_entry_usn", NULL, SYSDB_USN, NULL },
    { "ldap_user_shadow_last_change", "shadowLastChange", SYSDB_SHADOWPW_LASTCHANGE, NULL },
    { "ldap_user_shadow_min", "shadowMin", SYSDB_SHADOWPW_MIN, NULL },
    { "ldap_user_shadow_max", "shadowMax", SYSDB_SHADOWPW_MAX, NULL },
    { "ldap_user_shadow_warning", "shadowWarning", SYSDB_SHADOWPW_WARNING, NULL },
    { "ldap_user_shadow_inactive", "shadowInactive", SYSDB_SHADOWPW_INACTIVE, NULL },
    { "ldap_user_shadow_expire", "shadowExpire", SYSDB_SHADOWPW_EXPIRE, NULL },
    { "ldap_user_shadow_flag", "shadowFlag", SYSDB_SHADOWPW_FLAG, NULL },
    { "ldap_user_krb_last_pwd_change", "krbLastPwdChange", SYSDB_KRBPW_LASTCHANGE, NULL },
    { "ldap_user_krb_password_expiration", "krbPasswordExpiration", SYSDB_KRBPW_EXPIRATION, NULL },
    { "ldap_pwd_attribute", "pwdAttribute", SYSDB_PWD_ATTRIBUTE, NULL },
    { "ldap_user_authorized_service", "authorizedService", SYSDB_AUTHORIZED_SERVICE, NULL },
    { "ldap_user_ad_account_expires", "accountExpires", SYSDB_AD_ACCOUNT_EXPIRES, NULL},
    { "ldap_user_ad_user_account_control", "userAccountControl", SYSDB_AD_USER_ACCOUNT_CONTROL, NULL},
    { "ldap_ns_account_lock", "nsAccountLock", SYSDB_NS_ACCOUNT_LOCK, NULL},
    { "ldap_user_authorized_host", "host", SYSDB_AUTHORIZED_HOST, NULL },
    { "ldap_user_nds_login_disabled", "loginDisabled", SYSDB_NDS_LOGIN_DISABLED, NULL },
    { "ldap_user_nds_login_expiration_time", "loginExpirationTime", SYSDB_NDS_LOGIN_EXPIRATION_TIME, NULL },
    { "ldap_user_nds_login_allowed_time_map", "loginAllowedTimeMap", SYSDB_NDS_LOGIN_ALLOWED_TIME_MAP, NULL },
    { "ldap_user_ssh_public_key", NULL, SYSDB_SSH_PUBKEY, NULL },
    SDAP_ATTR_MAP_TERMINATOR
};

struct sdap_attr_map rfc2307_group_map[] = {
    { "ldap_group_object_class", "posixGroup", SYSDB_GROUP_CLASS, NULL },
    { "ldap_group_name", "cn", SYSDB_NAME, NULL },
    { "ldap_group_pwd", "userPassword", SYSDB_PWD, NULL },
    { "ldap_group_gid_number", "gidNumber", SYSDB_GIDNUM, NULL },
    { "ldap_group_member", "memberuid", SYSDB_MEMBER, NULL },
    { "ldap_group_uuid", NULL, SYSDB_UUID, NULL },
    { "ldap_group_objectsid", NULL, SYSDB_SID, NULL },
    { "ldap_group_modify_timestamp", "modifyTimestamp", SYSDB_ORIG_MODSTAMP, NULL },
    { "ldap_group_entry_usn", NULL, SYSDB_USN, NULL },
    SDAP_ATTR_MAP_TERMINATOR
};

struct sdap_attr_map rfc2307bis_user_map[] = {
    { "ldap_user_object_class", "posixAccount", SYSDB_USER_CLASS, NULL },
    { "ldap_user_name", "uid", SYSDB_NAME, NULL },
    { "ldap_user_pwd", "userPassword", SYSDB_PWD, NULL },
    { "ldap_user_uid_number", "uidNumber", SYSDB_UIDNUM, NULL },
    { "ldap_user_gid_number", "gidNumber", SYSDB_GIDNUM, NULL },
    { "ldap_user_gecos", "gecos", SYSDB_GECOS, NULL },
    { "ldap_user_home_directory", "homeDirectory", SYSDB_HOMEDIR, NULL },
    { "ldap_user_shell", "loginShell", SYSDB_SHELL, NULL },
    { "ldap_user_principal", "krbPrincipalName", SYSDB_UPN, NULL },
    { "ldap_user_fullname", "cn", SYSDB_FULLNAME, NULL },
    { "ldap_user_member_of", "memberOf", SYSDB_MEMBEROF, NULL },
    /* FIXME: this is 389ds specific */
    { "ldap_user_uuid", "nsUniqueId", SYSDB_UUID, NULL },
    { "ldap_user_objectsid", NULL, SYSDB_SID, NULL },
    { "ldap_user_primary_group", NULL, SYSDB_PRIMARY_GROUP, NULL },
    { "ldap_user_modify_timestamp", "modifyTimestamp", SYSDB_ORIG_MODSTAMP, NULL },
    { "ldap_user_entry_usn", NULL, SYSDB_USN, NULL },
    { "ldap_user_shadow_last_change", "shadowLastChange", SYSDB_SHADOWPW_LASTCHANGE, NULL },
    { "ldap_user_shadow_min", "shadowMin", SYSDB_SHADOWPW_MIN, NULL },
    { "ldap_user_shadow_max", "shadowMax", SYSDB_SHADOWPW_MAX, NULL },
    { "ldap_user_shadow_warning", "shadowWarning", SYSDB_SHADOWPW_WARNING, NULL },
    { "ldap_user_shadow_inactive", "shadowInactive", SYSDB_SHADOWPW_INACTIVE, NULL },
    { "ldap_user_shadow_expire", "shadowExpire", SYSDB_SHADOWPW_EXPIRE, NULL },
    { "ldap_user_shadow_flag", "shadowFlag", SYSDB_SHADOWPW_FLAG, NULL },
    { "ldap_user_krb_last_pwd_change", "krbLastPwdChange", SYSDB_KRBPW_LASTCHANGE, NULL },
    { "ldap_user_krb_password_expiration", "krbPasswordExpiration", SYSDB_KRBPW_EXPIRATION, NULL },
    { "ldap_pwd_attribute", "pwdAttribute", SYSDB_PWD_ATTRIBUTE, NULL },
    { "ldap_user_authorized_service", "authorizedService", SYSDB_AUTHORIZED_SERVICE, NULL },
    { "ldap_user_ad_account_expires", "accountExpires", SYSDB_AD_ACCOUNT_EXPIRES, NULL},
    { "ldap_user_ad_user_account_control", "userAccountControl", SYSDB_AD_USER_ACCOUNT_CONTROL, NULL},
    { "ldap_ns_account_lock", "nsAccountLock", SYSDB_NS_ACCOUNT_LOCK, NULL},
    { "ldap_user_authorized_host", "host", SYSDB_AUTHORIZED_HOST, NULL },
    { "ldap_user_nds_login_disabled", "loginDisabled", SYSDB_NDS_LOGIN_DISABLED, NULL },
    { "ldap_user_nds_login_expiration_time", "loginExpirationTime", SYSDB_NDS_LOGIN_EXPIRATION_TIME, NULL },
    { "ldap_user_nds_login_allowed_time_map", "loginAllowedTimeMap", SYSDB_NDS_LOGIN_ALLOWED_TIME_MAP, NULL },
    { "ldap_user_ssh_public_key", NULL, SYSDB_SSH_PUBKEY, NULL },
    SDAP_ATTR_MAP_TERMINATOR
};

struct sdap_attr_map rfc2307bis_group_map[] = {
    { "ldap_group_object_class", "posixGroup", SYSDB_GROUP_CLASS, NULL },
    { "ldap_group_name", "cn", SYSDB_NAME, NULL },
    { "ldap_group_pwd", "userPassword", SYSDB_PWD, NULL },
    { "ldap_group_gid_number", "gidNumber", SYSDB_GIDNUM, NULL },
    { "ldap_group_member", "member", SYSDB_MEMBER, NULL },
    /* FIXME: this is 389ds specific */
    { "ldap_group_uuid", "nsUniqueId", SYSDB_UUID, NULL },
    { "ldap_group_objectsid", NULL, SYSDB_SID, NULL },
    { "ldap_group_modify_timestamp", "modifyTimestamp", SYSDB_ORIG_MODSTAMP, NULL },
    { "ldap_group_entry_usn", NULL, SYSDB_USN, NULL },
    SDAP_ATTR_MAP_TERMINATOR
};

struct sdap_attr_map ad2008r2_user_map[] = {
    { "ldap_user_object_class", "user", SYSDB_USER_CLASS, NULL },
    { "ldap_user_name", "sAMAccountName", SYSDB_NAME, NULL },
    { "ldap_user_pwd", "unixUserPassword", SYSDB_PWD, NULL },
    { "ldap_user_uid_number", "uidNumber", SYSDB_UIDNUM, NULL },
    { "ldap_user_gid_number", "gidNumber", SYSDB_GIDNUM, NULL },
    { "ldap_user_gecos", "gecos", SYSDB_GECOS, NULL },
    { "ldap_user_home_directory", "unixHomeDirectory", SYSDB_HOMEDIR, NULL },
    { "ldap_user_shell", "loginShell", SYSDB_SHELL, NULL },
    { "ldap_user_principal", "userPrincipalName", SYSDB_UPN, NULL },
    { "ldap_user_fullname", "name", SYSDB_FULLNAME, NULL },
    { "ldap_user_member_of", "memberOf", SYSDB_MEMBEROF, NULL },
    { "ldap_user_uuid", "objectGUID", SYSDB_UUID, NULL },
    { "ldap_user_objectsid", "objectSID", SYSDB_SID, NULL },
    { "ldap_user_primary_group", "primaryGroupID", SYSDB_PRIMARY_GROUP, NULL },
    { "ldap_user_modify_timestamp", "whenChanged", SYSDB_ORIG_MODSTAMP, NULL },
    { "ldap_user_entry_usn", SDAP_AD_USN, SYSDB_USN, NULL },
    { "ldap_user_shadow_last_change", NULL, SYSDB_SHADOWPW_LASTCHANGE, NULL },
    { "ldap_user_shadow_min", NULL, SYSDB_SHADOWPW_MIN, NULL },
    { "ldap_user_shadow_max", NULL, SYSDB_SHADOWPW_MAX, NULL },
    { "ldap_user_shadow_warning", NULL, SYSDB_SHADOWPW_WARNING, NULL },
    { "ldap_user_shadow_inactive", NULL, SYSDB_SHADOWPW_INACTIVE, NULL },
    { "ldap_user_shadow_expire", NULL, SYSDB_SHADOWPW_EXPIRE, NULL },
    { "ldap_user_shadow_flag", NULL, SYSDB_SHADOWPW_FLAG, NULL },
    { "ldap_user_krb_last_pwd_change", NULL, SYSDB_KRBPW_LASTCHANGE, NULL },
    { "ldap_user_krb_password_expiration", NULL, SYSDB_KRBPW_EXPIRATION, NULL },
    { "ldap_pwd_attribute", NULL, SYSDB_PWD_ATTRIBUTE, NULL },
    { "ldap_user_authorized_service", NULL, SYSDB_AUTHORIZED_SERVICE, NULL },
    { "ldap_user_ad_account_expires", "accountExpires", SYSDB_AD_ACCOUNT_EXPIRES, NULL},
    { "ldap_user_ad_user_account_control", "userAccountControl", SYSDB_AD_USER_ACCOUNT_CONTROL, NULL},
    { "ldap_ns_account_lock", NULL, SYSDB_NS_ACCOUNT_LOCK, NULL},
    { "ldap_user_authorized_host", NULL, SYSDB_AUTHORIZED_HOST, NULL },
    { "ldap_user_nds_login_disabled", NULL, SYSDB_NDS_LOGIN_DISABLED, NULL },
    { "ldap_user_nds_login_expiration_time", NULL, SYSDB_NDS_LOGIN_EXPIRATION_TIME, NULL },
    { "ldap_user_nds_login_allowed_time_map", NULL, SYSDB_NDS_LOGIN_ALLOWED_TIME_MAP, NULL },
    { "ldap_user_ssh_public_key", NULL, SYSDB_SSH_PUBKEY, NULL },
    SDAP_ATTR_MAP_TERMINATOR
};

struct sdap_attr_map ad2008r2_group_map[] = {
    { "ldap_group_object_class", "group", SYSDB_GROUP_CLASS, NULL },
    { "ldap_group_name", "name", SYSDB_NAME, NULL },
    { "ldap_group_pwd", NULL, SYSDB_PWD, NULL },
    { "ldap_group_gid_number", "gidNumber", SYSDB_GIDNUM, NULL },
    { "ldap_group_member", "member", SYSDB_MEMBER, NULL },
    { "ldap_group_uuid", "objectGUID", SYSDB_UUID, NULL },
    { "ldap_group_objectsid", "objectSID", SYSDB_SID, NULL },
    { "ldap_group_modify_timestamp", "whenChanged", SYSDB_ORIG_MODSTAMP, NULL },
    { "ldap_group_entry_usn", SDAP_AD_USN, SYSDB_USN, NULL },
    SDAP_ATTR_MAP_TERMINATOR
};

struct sdap_attr_map netgroup_map[] = {
    { "ldap_netgroup_object_class", "nisNetgroup", SYSDB_NETGROUP_CLASS, NULL },
    { "ldap_netgroup_name", "cn", SYSDB_NAME, NULL },
    { "ldap_netgroup_member", "memberNisNetgroup", SYSDB_ORIG_NETGROUP_MEMBER, NULL },
    { "ldap_netgroup_triple", "nisNetgroupTriple", SYSDB_NETGROUP_TRIPLE, NULL },
    /* FIXME: this is 389ds specific */
    { "ldap_netgroup_uuid", "nsUniqueId", SYSDB_UUID, NULL },
    { "ldap_netgroup_modify_timestamp", "modifyTimestamp", SYSDB_ORIG_MODSTAMP, NULL },
    SDAP_ATTR_MAP_TERMINATOR
};

struct sdap_attr_map native_sudorule_map[] = {
    { "ldap_sudorule_object_class", "sudoRole", SYSDB_SUDO_CACHE_AT_OC, NULL },
    { "ldap_sudorule_name", "cn", SYSDB_SUDO_CACHE_AT_CN, NULL },
    { "ldap_sudorule_command", "sudoCommand", SYSDB_SUDO_CACHE_AT_COMMAND, NULL },
    { "ldap_sudorule_host", "sudoHost", SYSDB_SUDO_CACHE_AT_HOST, NULL },
    { "ldap_sudorule_user", "sudoUser", SYSDB_SUDO_CACHE_AT_USER, NULL },
    { "ldap_sudorule_option", "sudoOption", SYSDB_SUDO_CACHE_AT_OPTION, NULL },
    { "ldap_sudorule_runasuser", "sudoRunAsUser", SYSDB_SUDO_CACHE_AT_RUNASUSER, NULL },
    { "ldap_sudorule_runasgroup", "sudoRunAsGroup", SYSDB_SUDO_CACHE_AT_RUNASGROUP, NULL },
    { "ldap_sudorule_notbefore", "sudoNotBefore", SYSDB_SUDO_CACHE_AT_NOTBEFORE, NULL },
    { "ldap_sudorule_notafter", "sudoNotAfter", SYSDB_SUDO_CACHE_AT_NOTAFTER, NULL },
    { "ldap_sudorule_order", "sudoOrder", SYSDB_SUDO_CACHE_AT_ORDER, NULL },
    { "ldap_sudorule_entry_usn", NULL, SYSDB_USN, NULL },
    SDAP_ATTR_MAP_TERMINATOR
};

struct sdap_attr_map service_map[] = {
    { "ldap_service_object_class", "ipService", SYSDB_SVC_CLASS, NULL },
    { "ldap_service_name", "cn", SYSDB_NAME, NULL },
    { "ldap_service_port", "ipServicePort", SYSDB_SVC_PORT, NULL },
    { "ldap_service_proto", "ipServiceProtocol", SYSDB_SVC_PROTO, NULL },
    { "ldap_service_entry_usn", NULL, SYSDB_USN, NULL },
    SDAP_ATTR_MAP_TERMINATOR
};

struct sdap_attr_map rfc2307_autofs_mobject_map[] = {
    { "ldap_autofs_map_object_class", "automountMap", SYSDB_AUTOFS_MAP_OC, NULL },
    { "ldap_autofs_map_name", "ou", SYSDB_AUTOFS_MAP_NAME, NULL },
    SDAP_ATTR_MAP_TERMINATOR
};

struct sdap_attr_map rfc2307_autofs_entry_map[] = {
    { "ldap_autofs_entry_object_class", "automount", SYSDB_AUTOFS_ENTRY_OC, NULL },
    { "ldap_autofs_entry_key", "cn", SYSDB_AUTOFS_ENTRY_KEY, NULL },
    { "ldap_autofs_entry_value", "automountInformation", SYSDB_AUTOFS_ENTRY_VALUE, NULL },
    SDAP_ATTR_MAP_TERMINATOR
};

struct sdap_attr_map rfc2307bis_autofs_mobject_map[] = {
    { "ldap_autofs_map_object_class", "automountMap", SYSDB_AUTOFS_MAP_OC, NULL },
    { "ldap_autofs_map_name", "automountMapName", SYSDB_AUTOFS_MAP_NAME, NULL },
    SDAP_ATTR_MAP_TERMINATOR
};

struct sdap_attr_map rfc2307bis_autofs_entry_map[] = {
    { "ldap_autofs_entry_object_class", "automount", SYSDB_AUTOFS_ENTRY_OC, NULL },
    { "ldap_autofs_entry_key", "automountKey", SYSDB_AUTOFS_ENTRY_KEY, NULL },
    { "ldap_autofs_entry_value", "automountInformation", SYSDB_AUTOFS_ENTRY_VALUE, NULL },
    SDAP_ATTR_MAP_TERMINATOR
};

#endif /* LDAP_OPTS_H_ */
