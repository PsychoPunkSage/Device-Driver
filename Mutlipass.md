## Multipass Installation:

> visit [Multipass](https://multipass.run/docs/install-multipass) <br>

> Select the OS: `Linux/Mac/Windows` <br>

<details>

<summary>
Issue with MacOS
</summary>

if `brew install multipass` doesn't work.<br>
Run `brew install --cask multipass`

</details>

> Follow the series of command.

## Instance creation:

| Command                                                                | Reason                                                                                                                         |
| ---------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------ |
| `multipass shell`                                                      | Prepare primary instance in background.<br>                                                                                    |
| `sudo vim /etc/ssh/sshd_config`                                        | 1. `:set nu` : to get line numbers in shell <br> 2. go to `line 61` i.e. `KeyboardInteractiveAuthentication` - turn it **yes** |
| `sudo systemctl daemon-reload`                                         | reload daemon with new config                                                                                                  |
| `sudo service ssh restart`                                             | restart ssh service                                                                                                            |
| `sudo passwd [username]`                                               | to set password for your instance                                                                                              |
| `hostname -I`                                                          | Get the IP Address                                                                                                             |
| Create SSH connection using **`Remote Explorer`** extension in VS-Code | Add `SSH` connection like this `ubuntu@[IP-ADDRESS]`                                                                           |

<details>

<summary>
Output
</summary>

```
multipass shell

Launched: primary
Mounted '/home/psychopunk_sage' into 'primary:Home'
Welcome to Ubuntu 24.04.1 LTS (GNU/Linux 6.8.0-44-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/pro

 System information as of Sun Oct  6 19:01:08 IST 2024

  System load:  0.27              Processes:             106
  Usage of /:   44.5% of 3.80GB   Users logged in:       0
  Memory usage: 21%               IPv4 address for ens3: 10.125.153.197
  Swap usage:   0%


Expanded Security Maintenance for Applications is not enabled.

41 updates can be applied immediately.
28 of these updates are standard security updates.
To see these additional updates run: apt list --upgradable

Enable ESM Apps to receive additional future security updates.
See https://ubuntu.com/esm or run: sudo pro status


ubuntu@primary:~$
```
</details>