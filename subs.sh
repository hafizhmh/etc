#!/bin/bash
subscription-manager remove --all
subscription-manager unregister
subscription-manager clean
subscription-manager register --username=hafizh_mh --password=Kartini16^^
subscription-manager refresh
POOLID=$(sudo subscription-manager list --available | grep 'Pool ID' | awk '{print $3}')
subscription-manager attach --pool=$POOLID
yum clean all
