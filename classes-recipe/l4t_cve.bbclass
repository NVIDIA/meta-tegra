def l4t_upstream_pv(d):
    return d.getVar('PV').split('-l4t')[0]

CVE_VERSION ?= "${@l4t_upstream_pv(d)}"
