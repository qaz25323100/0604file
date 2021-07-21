# Docker  

    docker run -it centos:centos7.1.1503 /bin/bash
  
# 設定 repository  
  
    centos:~ # vi /etc/yum.repos.d/mongodb-org.repo
    [mongodb-org]
    baseurl = https://repo.mongodb.org/yum/redhat/$releasever/mongodb-org/3.2/x86_64/
    gpgcheck = 1
    gpgkey = https://www.mongodb.org/static/pgp/server-3.2.asc
    name = mongodb-org
  
centos:~ # yum install --downloadonly --downloaddir=/opt/paks mongodb-org

## Problem

### 問題1.WSL runs via Docker like technology and has the same restrictions
> You have to point your web app inside the WSL to use the IP ‘0.0.0.0’ and then you can see the app in a browser at 127.0.0.1  
> from https://github.com/microsoft/WSL/discussions/2471  
