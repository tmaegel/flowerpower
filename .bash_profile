#
# ~/.bash_profile
#

[[ -f ~/.bashrc ]] && . ~/.bashrc

# automatically start ssh-agent and load the ssh-key(s) on login
if [ -z "$SSH_AUTH_SOCK" ] ; then
	# start ssh-agent
	eval `ssh-agent -s`
	# add github flowerpower ssh key
	ssh-add ~/.ssh/fp_github
fi
