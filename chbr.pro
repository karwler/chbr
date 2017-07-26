TEMPLATE = subdirs

SUBDIRS += chbr \
        chbrg \
        mod

chbr.depends = mod
chbrg.depends = mod
