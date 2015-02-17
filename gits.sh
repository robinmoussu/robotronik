#!/bin/sh
ROOTDIR=`pwd`
URLROOT="https://code.google.com/p/"
REPOS=(
    #"robotronik"
    "robotronik.asser"
    "robotronik.communication"
    "robotronik.olinpiades"
    "robotronik.alim"
    "robotronik.meca"
    "robotronik.stm32-base"
    "robotronik.strategie"
    "robotronik.chargeur"
    "robotronik.cartographie"
    )

cloneall() {
    for repo in "${REPOS[@]}" ; do
        echo "Dépôt $repo"
        if [ -d "$repo" ]; then
            echo "Le dépôt existe déjà"
        else
            git clone $URLROOT$repo "$@"
        fi
    done
}
pullall() {
    for repo in "${REPOS[@]}" ; do
        echo "Dépôt $repo"
        if [ -d "$repo" ]; then
            cd $repo
            git pull "$@"
            cd ..
        else
            echo "Le dépôt n'existe pas encore ! Veuillez le cloner d'abord."
        fi
    done
}
statusall() {
    for repo in "${REPOS[@]}" ; do
        echo "Dépôt $repo"
        if [ -d "$repo" ]; then
            cd $repo
            git status "$@"
            cd ..
        else
            echo "Le dépôt n'existe pas encore ! Veuillez le cloner d'abord."
        fi
    done
}

if [[ -z "$1" ]]; then
    echo "Pas d'arguments donnés !"
else
    case "$1" in
        clone|--clone|-c)
            shift
            cloneall
            ;;
        pull|--pull|-p)
            shift
            pullall
            ;;
        status|--status|-s)
            shift
            statusall
            ;;
        *)
            echo "Argument \"$1\" inconnu !"
            help
            ;;
    esac

fi

